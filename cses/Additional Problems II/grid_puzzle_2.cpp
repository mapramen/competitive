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
    fill(vis.begin(), vis.end(), false);

    for (int i = 0; i < n; ++i) {
      dfs(i);
    }
    reverse(topological_order.begin(), topological_order.end());

    for (int i : topological_order) {
      for (int edge_no : g[i]) {
        edge edg = e[edge_no];
        if (edg.cap) {
          pot[edg.v] = min(pot[edg.v], pot[i] + edg.cost);
        }
      }
    }

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

int main() {
  int n;
  scanf("%d", &n);

  mcmf<int, int> mcmf(1 + n + n + 1);
  int s = 0, t = 1 + n + n;

  int row_sum = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);

    row_sum += x;
    mcmf.add_edge(s, i, x, 0);
  }

  int col_sum = 0;
  for (int j = 1; j <= n; ++j) {
    int x;
    scanf("%d", &x);

    col_sum += x;
    mcmf.add_edge(n + j, t, x, 0);
  }

  if (row_sum != col_sum) {
    printf("-1\n");
    return 0;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int x;
      scanf("%d", &x);
      mcmf.add_edge(i, n + j, 1, -x);
    }
  }

  auto [flow, cost] = mcmf.solve(s, t, row_sum);
  if (flow != row_sum) {
    printf("-1\n");
    return 0;
  }

  printf("%d\n", -cost);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int edge_no : mcmf.g[i]) {
        auto edg = mcmf.e[edge_no];
        if (edg.v == n + j && edg.cap == 1) {
          putchar(edg.flow == 1 ? 'X' : '.');
          break;
        }
      }
    }
    putchar('\n');
  }

  return 0;
}