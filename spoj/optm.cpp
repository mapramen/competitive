#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1E9

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
    G[to].push_back(Edge(to, from, cap, 0ll, G[from].size() - 1));

    // for directed
    // G[to].push_back(Edge(to, from, 0ll, 0ll, G[from].size() - 1));
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

vector<int> Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  vector<pii> edges;
  while (m--) {
    int i, j;
    scanf("%d%d", &i, &j);
    edges.push_back({i, j});
  }

  int k;
  scanf("%d", &k);

  vector<int> marks(n + 1, -1);
  vector<int> ans(n);

  while (k--) {
    int i, p;
    scanf("%d%d", &i, &p);
    marks[i] = p;
    ans[i - 1] = p;
  }

  for (int b = 30; b > -1; --b) {
    int s = 0, t = n + 1;
    PushRelabel push_relabel = PushRelabel(1 + n + 1);

    for (int i = 1; i <= n; ++i) {
      if (marks[i] == -1) {
        push_relabel.AddEdge(s, i, 0);
        push_relabel.AddEdge(i, t, 0);
        continue;
      }

      if (marks[i] & (1 << b)) {
        push_relabel.AddEdge(s, i, INF);
        push_relabel.AddEdge(i, t, 0);
      } else {
        push_relabel.AddEdge(s, i, 0);
        push_relabel.AddEdge(i, t, INF);
      }
    }

    for (auto [i, j] : edges) {
      push_relabel.AddEdge(i, j, 1);
    }

    ll max_flow = push_relabel.GetMaxFlow(s, t);

    queue<int> Q;
    vector<bool> visited(n + 1);

    Q.push(s);
    visited[s] = true;

    while (!Q.empty()) {
      int i = Q.front();
      Q.pop();

      for (auto edge : push_relabel.G[i]) {
        int j = edge.to;
        if (edge.flow < edge.cap && !visited[j]) {
          visited[j] = true;
          Q.push(j);
        }
      }
    }

    for (int i = 0; i <= n + 1; ++i) {
      for (auto edge : push_relabel.G[i]) {
        int j = edge.to;
        if ((i == t || j == t) && visited[i] && !visited[j]) {
          ans[(i ^ j ^ t) - 1] |= (1 << b);
        }
      }
    }
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int x : Solve()) {
      printf("%d\n", x);
    }
  }
  return 0;
}