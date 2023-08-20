#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 50001
#define B 26
#define M (B * B)

char s[N];
vector<vector<pii>> adj(N + M);
int idx[B][B], from_dis[M][N + M], to_dis[M][N + M];
deque<int> Q;

void CheckAndPush(int d[N], int i, int j, int w) {
  int dj = d[i] + w;
  if (dj >= d[j]) {
    return;
  }

  d[j] = dj;

  if (w == 0) {
    Q.push_front(j);
  } else {
    Q.push_back(j);
  }
}

void BFS(int d[N], int s) {
  for (int i = 1; i < N + M; ++i) {
    d[i] = N + M;
  }

  CheckAndPush(d, 0, s, 0);

  while (!Q.empty()) {
    int i = Q.front();
    Q.pop_front();

    for (auto [j, w] : adj[i]) {
      CheckAndPush(d, i, j, w);
    }
  }
}

int main() {
  scanf("%s", s);

  int n = strlen(s);
  for (int i = 0, k = n; i < B; ++i) {
    for (int j = 0; j < B; ++j) {
      idx[i][j] = k++;
    }
  }

  for (int i = 1; i < n - 1; ++i) {
    adj[i].push_back({i + 1, 1});
    adj[i + 1].push_back({i, 1});
  }

  for (int i = 1; i < n; ++i) {
    int k = idx[s[i - 1] - 'a'][s[i] - 'a'];
    adj[i].push_back({k, 1});
    adj[k].push_back({i, 0});
  }

  for (int k = 0; k < M; ++k) {
    for (auto& p : adj[n + k]) {
      p.second = 1;
    }

    BFS(from_dis[k], n + k);

    for (auto& p : adj[n + k]) {
      p.second = 0;
    }

    BFS(to_dis[k], n + k);
  }

  int q;
  scanf("%d", &q);

  while (q--) {
    int i, j;
    scanf("%d%d", &i, &j);

    int ans = abs(j - i);
    for (int k = 0; k < B * B; ++k) {
      ans = min(ans, from_dis[k][i] + to_dis[k][j]);
    }

    printf("%d\n", ans);
  }

  return 0;
}