#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define et tuple<int,int,int,int>
#define InfCapacity 1000
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

void SortAndDedup(vector<int>& v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

void FillEdgesForHalf(vector<et>& edges, vector<int>& a, vector<int>& v, int m, int l, int r, bool in, int mul){
  for(int i = l; i <= r; ++i){
    int k = m + lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    int x = in ? k : 2 * i, y = in ? 2 * i - 1 : k;
    edges.push_back({x, y, 1, mul * a[i]});
  }
}

void FillEdges(vector<et>& edges, vector<int>& a, int&t, int l, int r){
  if(l == r){
    return;
  }

  int mid = (l + r) / 2;
  
  FillEdges(edges, a, t, l, mid);
  FillEdges(edges, a, t, mid + 1, r);

  vector<int> v(a.begin() + l, a.begin() + r + 1);
  SortAndDedup(v);

  int m = v.size();

  for(int i = 0, j = 1; j < v.size(); ++i, ++j){
    edges.push_back({t + i, t + j, InfCapacity, 0});
    edges.push_back({t + m + j, t + m + i, InfCapacity, 0});
  }

  FillEdgesForHalf(edges, a, v, t, l, mid, false, -1);
  FillEdgesForHalf(edges, a, v, t, mid + 1, r, true, 1);

  FillEdgesForHalf(edges, a, v, t + m, l, mid, false, 1);
  FillEdgesForHalf(edges, a, v, t + m, mid + 1, r, true, -1);

  t += 2 * m;
}

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> a(n + 1);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  vector<et> edges;
  int s = 0, t = n + n + 1;
  FillEdges(edges, a, t, 1, n);

  mcmf<int,ll> mcmf(t + 1);

  for(int i = 1; i <= n; ++i){
    mcmf.add_edge(s, 2 * i - 1, 1, 0);
    mcmf.add_edge(2 * i, t, 1, 0);
    mcmf.add_edge(2 * i - 1, 2 * i, 1, -InfCost);
  }

  for(et& e: edges){
    int x = get<0>(e), y = get<1>(e), capacity = get<2>(e), cost = get<3>(e);
    mcmf.add_edge(x, y, capacity, cost);
  }

  pair<int,ll> ans = mcmf.solve(s, t, min(n, k));
  return ans.second + 1ll * n * InfCost;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}