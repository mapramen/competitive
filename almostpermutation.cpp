#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 51
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

int l[N], r[N];

int main(){
  int n, q;

  cin >> n >> q;

  for(int i = 1; i <= n; ++i)
    l[i] = 1, r[i] = n;

  while(q--){
    int t, i, j, x;
    cin >> t >> i >> j >> x;

    for(int k = i; k <= j; ++k){
      if(t == 1)
        l[k] = max(l[k], x);
      else
        r[k] = min(r[k], x);
    }
  }

  for(int i = 1; i <= n; ++i){
    if(l[i] > r[i]){
      cout << "-1\n";
      return 0;
    }
  }

  MinimumCostMaximumFlow mcmf(1 + n + n + 1);
  int s = 0, t = n + n + 1;

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j){
      mcmf.AddDirectedEdge(s, i, 1, 2 * j - 1);
    }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      if(l[j] <= i && i <= r[j]){
        mcmf.AddDirectedEdge(i, n + j, 1, 0);
      }
    }
  }

  for(int j = n + 1; j < t; ++j)
    mcmf.AddDirectedEdge(j, t, 1, 0);

  int cost = mcmf.GetMinCostMaxFlow(s, t, n, true).first;

  cout << cost << '\n';

  return 0;
}
