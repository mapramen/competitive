#include <bits/stdc++.h>
#pragma GCC target("popcnt")

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 50001

vector<vector<int>> adj(N);
bitset<N> dp[N];
bool visited[N];

void DFS(int i) {
  if (visited[i]) {
    return;
  }

  visited[i] = true;
  dp[i].set(i);
  for (int j : adj[i]) {
    DFS(j);
    dp[i] |= dp[j];
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  while (m--) {
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
  }

  for (int i = 1; i <= n; ++i) {
    DFS(i);
  }

  for (int i = 1; i <= n; ++i) {
    printf("%lu ", dp[i].count());
  }
  printf("\n");

  return 0;
}