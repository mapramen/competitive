#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define N 101

vector<vector<pii>> adj(N);
int parent[N];
priority_queue<pli, vector<pli>, greater<pli>> Q;
ll dist[N];

void CheckAndPush(int i, ll di, int p) {
  if (di < dist[i]) {
    parent[i] = p;
    dist[i] = di;
    Q.push({di, i});
  }
}

void Dijkstra(int n, int s) {
  for (int i = 1; i <= n; ++i) {
    dist[i] = LLONG_MAX;
    parent[i] = 0;
  }

  CheckAndPush(s, 0, 0);
  while (!Q.empty()) {
    auto [di, i] = Q.top();
    Q.pop();

    if (di != dist[i]) {
      continue;
    }

    for (auto [j, w] : adj[i]) {
      CheckAndPush(j, di + w, i);
    }
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  while (m--) {
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  Dijkstra(n, 1);

  if (dist[n] == LLONG_MAX) {
    printf("inf\n");
    return 0;
  }

  vector<pli> v;
  for (int i = 1; i <= n; ++i) {
    if (dist[i] > dist[n]) {
      continue;
    }
    v.push_back({dist[i], i});
  }
  sort(v.begin(), v.end());

  printf("%lld %lu\n", dist[n], v.size() - 1);
  for (int k = 1; k < v.size(); ++k) {
    string s = string(n, '0');
    for (int i = 0; i < k; ++i) {
      s[v[i].second - 1] = '1';
    }
    printf("%s %lld\n", s.c_str(), v[k].first - v[k - 1].first);
  }

  return 0;
}