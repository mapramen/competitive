#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define et tuple<int,int,int,int>
#define InfCost 100000000

template<typename Cap, typename Cost>
struct mcmf {
  struct edge {
    int v;
    Cap cap, flow;
    Cost cost;
  };
  int n;
  vector<edge> e;
  vector<vector<int>> g;
  vector<Cost> dist, pot;
  vector<Cap> f;
  vector<bool> vis;
  vector<int> par;
  vector<int> topological_order;

  bool n2dijkstra = false;
  mcmf(int n) : n(n), g(n), dist(n), pot(n), f(n), vis(n), par(n) {}
  void add_edge(int u, int v, Cap cap, Cost cost) {
    int k = e.size();
    e.push_back({v, cap, 0, cost});
    e.push_back({u, 0, 0, -cost});
    g[u].push_back(k);
    g[v].push_back(k ^ 1);
  }

  void dfs(int i){
    if(vis[i]){
      return;
    }

    vis[i] = true;

    for(int edge_no: g[i]){
      edge edg = e[edge_no];
      if(edg.cap){
        dfs(edg.v);
      }
    }

    topological_order.push_back(i);
  }

  pair<Cap, Cost> solve(int s, int t, Cap max_flow) {
    fill(vis.begin(), vis.end(), false);

    for(int i = 0; i < n; ++i){
      dfs(i);
    }
    reverse(topological_order.begin(), topological_order.end());
    
    for(int i : topological_order){
      for(int edge_no: g[i]){
        edge edg = e[edge_no];
        if(edg.cap){
          pot[edg.v] = min(pot[edg.v], pot[i] + edg.cost);
        }
      }
    }

    Cap flow = 0;
    Cost cost = 0;
    while(flow < max_flow) {
      fill(dist.begin(), dist.end(), numeric_limits<Cost>::max());
      fill(vis.begin(), vis.end(), false);
      dist[s] = 0;
      f[s] = numeric_limits<Cap>::max();
      if(n2dijkstra) {
        while(true) {
          int x = -1; Cost d = numeric_limits<Cost>::max();
          for(int i = 0; i < n; i++) {
            if(!vis[i] && dist[i] < d) {
              x = i;
              d = dist[x];
            }
          }
          if(x == -1) break;
          vis[x] = true;
          for(int i : g[x]) {
            Cost d2 = d + e[i].cost + pot[x] - pot[e[i].v];
            if(!vis[e[i].v] && e[i].flow < e[i].cap && d2 < dist[e[i].v]) {
              dist[e[i].v] = d2;
              f[e[i].v] = min(f[x], e[i].cap - e[i].flow);
              par[e[i].v] = i;
            }
          }
        }
      }else {
        priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<>> Q;
        Q.push({0, s});
        while(!Q.empty()) {
          Cost d; int x;
          tie(d, x) = Q.top(); Q.pop();
          if(vis[x]) continue;
          vis[x] = true;
          for(int i : g[x]) {
            Cost d2 = d + e[i].cost + pot[x] - pot[e[i].v];
            if(!vis[e[i].v] && e[i].flow < e[i].cap && d2 < dist[e[i].v]) {
              dist[e[i].v] = d2;
              f[e[i].v] = min(f[x], e[i].cap - e[i].flow);
              par[e[i].v] = i;
              Q.push({d2, e[i].v});
            }
          }
        }
      }
      if(!vis[t]) break;
      for(int i = 0; i < n; i++) {
        dist[i] += pot[i] - pot[s];
      }
      cost += dist[t] * f[t];
      flow += f[t];
      int x = t;
      while(x != s) {
        e[par[x]].flow += f[t];
        e[par[x] ^ 1].flow -= f[t];
        x = e[par[x] ^ 1].v;
      }
      dist.swap(pot);
    }
    return {flow, cost};
  }
};

bool IsPrime(int n){
  for(int i = 2; i * i <= n; ++i){
    if(n % i == 0){
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  scanf("%d", &n);

  vector<int> a(n + 1);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  vector<int> b;
  for(int i = 2; i <= 2000; ++i){
    if(IsPrime(i)){
      b.push_back(i);
    }
  }

  int s = 0, t = n + b.size() + 1;
  mcmf<int,int> mcmf(t + 1);

  for(int i = 1; i <= n; ++i){
    for(int j = 0; j < b.size(); ++j){
      if(a[i] % b[j] == 0){
        mcmf.add_edge(i, n + j + 1, 1, -(a[i] - a[i] / b[j]));
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    mcmf.add_edge(s, i, 1, 0);
    mcmf.add_edge(i, t, 1, 0);
  }

  for(int j = 0; j < b.size(); ++j){
    mcmf.add_edge(n + j + 1, t, 1, 0);
  }

  int ans = mcmf.solve(s, t, n).second;
  for(int i = 1; i <= n; ++i){
    ans += a[i];
  }

  printf("%d\n", ans);

  return 0;
}