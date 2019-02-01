#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 501
#define InfCapacity 1000
#define InfCost 1000000

struct MinimumCostMaximumFlow{
  typedef int Flow;
  typedef int Cost;

  struct Edge{
    int to, toAdjIndex;
    Flow capacity;
    Cost cost;

    Edge(int to, int toAdjIndex, Flow capacity, Cost cost) : to(to), toAdjIndex(toAdjIndex), capacity(capacity), cost(cost) {}
  };

  //n = no. of vertices [0, n)
  int n;
  vector< vector<Edge> > adj;
  vector<int> parent, parentAdjIndex;
  vector<Cost> dist, potential;
  vector<bool> visited;

  MinimumCostMaximumFlow(int n) : n(n), adj(n), parent(n), parentAdjIndex(n), dist(n), potential(n), visited(n) {}

  void AddDirectedEdge(int i, int j, Flow capacity, Cost cost){
    adj[i].PB(Edge(j, adj[j].size(), capacity, cost));
    adj[j].PB(Edge(i, adj[i].size() - 1, 0, -cost));
  }

  void AddUndirectedEdge(int i, int j, Flow capacity, Cost cost){
    AddDirectedEdge(i, j, capacity, cost);
    AddDirectedEdge(j, i, capacity, cost);
  }

  void BellmanFord(int s){
    fill(dist.begin(), dist.end(), InfCost);
    dist[s] = 0;
    while(true){
      bool update = false;
      for(int i = 0; i < n; ++i){
        if(dist[i] == InfCost)
          continue;
        for(int ei = 0; ei < adj[i].size(); ++ei){
          const Edge &e = adj[i][ei];
          if(e.capacity <= 0) continue;
          int j = e.to;
          Cost d = dist[i] + e.cost + potential[i] - potential[j];
          if(d < dist[j]){
            dist[j] = d;
            parent[j] = i;
            parentAdjIndex[j] = ei;
            update = true;
          }
        }
      }
      if(!update)
        break;
    }

    for(int i = 0; i < n; ++i)
      visited[i] = (dist[i] < InfCost);
  }

  void Dijkstra(int s){
    priority_queue< pair<Cost, int> > Q;

    fill(visited.begin(), visited.end(), false);
    fill(dist.begin(), dist.end(), InfCost);
    dist[s] = 0;
    Q.push(MP(-0, s));

    while(!Q.empty()){
      int i = Q.top().second;
      Q.pop();

      if(visited[i])
        continue;

      for(int ei = 0; ei < adj[i].size(); ++ei){
        const Edge &e = adj[i][ei];
        if(e.capacity <= 0) continue;
        int j = e.to;
        Cost d = dist[i] + e.cost + potential[i] - potential[j];
        if(d < dist[j]){
          dist[j] = d;
          parent[j] = i;
          parentAdjIndex[j] = ei;
          Q.push(MP(-d, j));
        }
      }

      visited[i] = true;
    }
  }

  void ReduceCost(){
    for(int i = 0; i < n; ++i)
      potential[i] += dist[i];
  }

  pair<Cost, Flow> GetMinCostMaxFlow(int s, int t, Flow maxFlow, bool bellmanFord){
    Cost totalCost = 0;
    Flow totalFlow = 0;

    while(maxFlow){
      if(bellmanFord || totalFlow == 0)
        BellmanFord(s);
      else
        Dijkstra(s);

      if(visited[t] == 0)
        break;

      Flow currentFlow = maxFlow;
      Cost currentCost = 0;

      for(int v = t; v != s; v = parent[v]){
        int u = parent[v];
        const Edge &e = adj[u][parentAdjIndex[v]];
        currentFlow = min(currentFlow, e.capacity);
        currentCost += e.cost;
      }

      for(int v = t; v != s; v = parent[v]){
        int u = parent[v];
        Edge &e = adj[u][parentAdjIndex[v]];
        e.capacity -= currentFlow;
        adj[v][e.toAdjIndex].capacity += currentFlow;
      }

      totalFlow += currentFlow;
      totalCost += currentCost * currentFlow;
      maxFlow -= currentFlow;

      if(!bellmanFord)
        ReduceCost();
    }

    return MP(totalCost, totalFlow);
  }
};


vector< vector<int> > adj1(N), adj2(N);
int n, a[N], b[N], sourceFlow, sinkFlow;
bool isConstrained[N];
MinimumCostMaximumFlow mcmf(2 * N);

bool DFS(vector< vector<int> >& adj, int i, int p, bool sourceDFS){
  b[i] = a[i];
  bool valid = 1;

  for(auto j : adj[i]){
    if(j == p){
      continue;
    }

    valid &= DFS(adj, j, i, sourceDFS);

    if(isConstrained[i]){
      b[i] -= a[j];
    }
    else{
      a[i] += a[j];
    }

    if(isConstrained[j]){
      continue;
    }

    int u = sourceDFS ? i : n + j;
    int v = sourceDFS ? j : n + i;

    mcmf.AddDirectedEdge(u, v, InfCapacity, 0);
  }

  if(isConstrained[i] && b[i] > 0){
    int u = sourceDFS ? 0 : n + i;
    int v = sourceDFS ? i : 1 + n + n;
    mcmf.AddDirectedEdge(u, v, b[i], 0);
  }

  return (valid & (b[i] >= 0));
}

void InputGraph(vector< vector<int> >& adj){
  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }
}

bool InputConstraintAndValidate(vector< vector<int> >& adj, int root, bool sourceGraph){
  for(int i = 1; i <= n; ++i){
    a[i] = 0;
    b[i] = 0;
    isConstrained[i] = 0;
  }

  int q;
  scanf("%d", &q);
  while(q--){
    int i, x;
    scanf("%d%d", &i, &x);
    a[i] = x;
    isConstrained[i] = 1;
  }

  if(sourceGraph){
    sourceFlow = a[root];
  }
  else{
    sinkFlow = a[root];
  }

  return DFS(adj, root, 0, sourceGraph);
}

int main(){
  int root1, root2;

  scanf("%d%d%d", &n, &root1, &root2);

  for(int i = 1; i <= n; ++i){
    int c;
    scanf("%d", &c);
    mcmf.AddDirectedEdge(i, n + i, 1, -c);
  }

  InputGraph(adj1);
  InputGraph(adj2);

  if(!InputConstraintAndValidate(adj1, root1, 1) || !InputConstraintAndValidate(adj2, root2, 0) || sourceFlow != sinkFlow){
    printf("-1\n");
    return 0;
  }

  int s = 0, t = 1 + n + n;

  int flow, cost;
  tie(cost, flow) = mcmf.GetMinCostMaxFlow(s, t, sourceFlow, true);

  int ans = (flow != sourceFlow) ? -1 : -cost;

  printf("%d\n", ans);

  return 0;
}
