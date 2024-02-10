#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

struct Edge {
  int from, to, index;
  ll cap, flow;
  Edge(int from, int to, ll cap, ll flow, int index)
      : from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
  int N;
  vector<vector<Edge>> G;
  vector<ll> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N)
      : N(N), G(N), excess(N), dist(N), active(N), count(2 * N) {}

  void AddEdge(int from, int to, ll cap) {
    G[from].push_back(Edge(from, to, cap, 0ll, G[to].size()));
    if (from == to) {
      G[from].back().index++;
    }
    // for undirected
    // G[to].push_back(Edge(to, from, cap, 0ll, G[from].size() - 1));

    // for directed
    G[to].push_back(Edge(to, from, 0ll, 0ll, G[from].size() - 1));
  }

  void Enqueue(int v) {
    if (!active[v] && excess[v] > 0) {
      active[v] = true;
      Q.push(v);
    }
  }

  void Push(Edge& e) {
    ll amt = min(excess[e.from], e.cap - e.flow);
    if (dist[e.from] <= dist[e.to] || amt == 0) {
      return;
    }
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
    Enqueue(e.to);
  }

  void Gap(int k) {
    for (int v = 0; v < N; ++v) {
      if (dist[v] < k) {
        continue;
      }
      count[dist[v]]--;
      dist[v] = max(dist[v], N + 1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2 * N;
    for (int i = 0; i < G[v].size(); ++i) {
      if (G[v][i].cap - G[v][i].flow > 0) {
        dist[v] = min(dist[v], dist[G[v][i].to] + 1);
      }
    }
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); ++i) {
      Push(G[v][i]);
    }
    if (excess[v] > 0) {
      if (count[dist[v]] == 1) {
        Gap(dist[v]);
      } else {
        Relabel(v);
      }
    }
  }

  ll GetMaxFlow(int s, int t) {
    count[0] = N - 1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); ++i) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }

    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }

    ll totflow = 0;
    for (int i = 0; i < G[s].size(); ++i) {
      totflow += G[s][i].flow;
    }
    return totflow;
  }
};

int Calculate(int n, vector<vector<int>>& adj, int s, int t) {
  PushRelabel push_relabel = PushRelabel(2 * n);

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((i == s && j == t) || adj[i][j] == 0) {
        continue;
      }
      push_relabel.AddEdge(2 * i + 1, 2 * j, 1);
      push_relabel.AddEdge(2 * j + 1, 2 * i, 1);
    }
  }

  for (int i = 0; i < n; ++i) {
    push_relabel.AddEdge(2 * i, 2 * i + 1, 1);
  }

  return push_relabel.GetMaxFlow(2 * s + 1, 2 * t);
}

int Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  vector<vector<int>> adj(n, vector<int>(n));
  while (m--) {
    int i, j;
    scanf(" (%d,%d)", &i, &j);
    adj[i][j] = 1;
    adj[j][i] = 1;
  }

  int ans = n;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (adj[i][j] == 1) {
        continue;
      }
      ans = min(ans, Calculate(n, adj, i, j));
    }
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}