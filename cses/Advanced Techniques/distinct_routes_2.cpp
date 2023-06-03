#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

template <typename Cap, typename Cost>
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
  mcmf(int n)
      : n(n), g(n), dist(n), pot(n), f(n), vis(n), par(n) {}
  void add_edge(int u, int v, Cap cap, Cost cost) {
    int k = e.size();
    e.push_back({v, cap, 0, cost});
    e.push_back({u, 0, 0, -cost});
    g[u].push_back(k);
    g[v].push_back(k ^ 1);
  }

  void dfs(int i) {
    if (vis[i]) {
      return;
    }

    vis[i] = true;

    for (int edge_no : g[i]) {
      edge edg = e[edge_no];
      if (edg.cap) {
        dfs(edg.v);
      }
    }

    topological_order.push_back(i);
  }

  pair<Cap, Cost> solve(int s, int t, Cap max_flow) {
    // fill(vis.begin(), vis.end(), false);

    // for (int i = 0; i < n; ++i) {
    //   dfs(i);
    // }
    // reverse(topological_order.begin(), topological_order.end());

    // for (int i : topological_order) {
    //   for (int edge_no : g[i]) {
    //     edge edg = e[edge_no];
    //     if (edg.cap) {
    //       pot[edg.v] = min(pot[edg.v], pot[i] + edg.cost);
    //     }
    //   }
    // }

    Cap flow = 0;
    Cost cost = 0;
    while (flow < max_flow) {
      fill(dist.begin(), dist.end(), numeric_limits<Cost>::max());
      fill(vis.begin(), vis.end(), false);
      dist[s] = 0;
      f[s] = max_flow - flow;
      if (n2dijkstra) {
        while (true) {
          int x = -1;
          Cost d = numeric_limits<Cost>::max();
          for (int i = 0; i < n; i++) {
            if (!vis[i] && dist[i] < d) {
              x = i;
              d = dist[x];
            }
          }
          if (x == -1)
            break;
          vis[x] = true;
          for (int i : g[x]) {
            Cost d2 = d + e[i].cost + pot[x] - pot[e[i].v];
            if (!vis[e[i].v] && e[i].flow < e[i].cap && d2 < dist[e[i].v]) {
              dist[e[i].v] = d2;
              f[e[i].v] = min(f[x], e[i].cap - e[i].flow);
              par[e[i].v] = i;
            }
          }
        }
      } else {
        priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<>> Q;
        Q.push({0, s});
        while (!Q.empty()) {
          Cost d;
          int x;
          tie(d, x) = Q.top();
          Q.pop();
          if (vis[x])
            continue;
          vis[x] = true;
          for (int i : g[x]) {
            Cost d2 = d + e[i].cost + pot[x] - pot[e[i].v];
            if (!vis[e[i].v] && e[i].flow < e[i].cap && d2 < dist[e[i].v]) {
              dist[e[i].v] = d2;
              f[e[i].v] = min(f[x], e[i].cap - e[i].flow);
              par[e[i].v] = i;
              Q.push({d2, e[i].v});
            }
          }
        }
      }
      if (!vis[t])
        break;
      for (int i = 0; i < n; i++) {
        dist[i] += pot[i] - pot[s];
      }
      cost += dist[t] * f[t];
      flow += f[t];
      int x = t;
      while (x != s) {
        e[par[x]].flow += f[t];
        e[par[x] ^ 1].flow -= f[t];
        x = e[par[x] ^ 1].v;
      }
      dist.swap(pot);
    }
    return {flow, cost};
  }
};

void ExtractPath(vector<set<int>>& adj, vector<int>& path, int n, int i) {
  path.push_back(i);
  if (i == n - 1) {
    return;
  }

  int j = *adj[i].begin();
  adj[i].erase(j);
  ExtractPath(adj, path, n, j);
}

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  mcmf<int, int> mcmf(n);

  while (m--) {
    int i, j;
    scanf("%d%d", &i, &j);
    --i, --j;
    mcmf.add_edge(i, j, 1, 1);
  }

  auto [flow, cost] = mcmf.solve(0, n - 1, k);
  if (flow != k) {
    printf("-1\n");
    return 0;
  }

  printf("%d\n", cost);

  vector<set<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    for (int edge_no : mcmf.g[i]) {
      if (mcmf.e[edge_no].flow == 1 && mcmf.e[edge_no].cost == 1) {
        adj[i].insert(mcmf.e[edge_no].v);
      }
    }
  }

  for (int x = 1; x <= k; ++x) {
    vector<int> path;
    ExtractPath(adj, path, n, 0);

    printf("%lu\n", path.size());
    for (int i : path) {
      printf("%d ", i + 1);
    }
    printf("\n");
  }

  return 0;
}