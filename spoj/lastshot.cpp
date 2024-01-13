#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 10001

vector<vector<int>> adj(N);
bool visited[N];

int DFS(int i) {
  if (visited[i]) {
    return 0;
  }

  visited[i] = true;

  int ans = 1;
  for (int j : adj[i]) {
    ans += DFS(j);
  }
  return ans;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  while (m--) {
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      visited[j] = false;
    }
    ans = max(ans, DFS(i));
  }

  printf("%d\n", ans);

  return 0;
}