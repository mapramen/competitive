#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define InfCapacity 1000
#define InfCost 1000000000

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

int main(){
  int n;

  scanf("%d", &n);

  MinimumCostMaximumFlow mcmf(1 + n + n + n + 1 + 1 + 1);
  int s = 0, n1 = n, n2 = n + n, m1 = n + n + n + 1, m2 = m1 + 1, t = m2 + 1;

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      int c;
      scanf("%d", &c);
      mcmf.AddDirectedEdge(i, n1 + j, 1, -c);
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      int c;
      scanf("%d", &c);
      mcmf.AddDirectedEdge(i, n2 + j, 1, -c);
    }
  }

  for(int i = 1; i <= n; ++i)
    mcmf.AddDirectedEdge(0, i, 1, 0);

  for(int j = 1; j <= n; ++j){
    mcmf.AddDirectedEdge(n1 + j, m1, 1, 0);
    mcmf.AddDirectedEdge(n2 + j, m2, 1, 0);
  }

  mcmf.AddDirectedEdge(m1, t, n / 2, 0);
  mcmf.AddDirectedEdge(m2, t, n / 2, 0);

  printf("%d\n", -mcmf.GetMinCostMaxFlow(s, t, n, true).first);
  
  return 0;
}
