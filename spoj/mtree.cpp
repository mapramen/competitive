#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001
#define MOD 1000000007

vector<vector<pii>> adj(N);

pii DFS(int i, int p) {
  int ans = 0, sum_of_products = 1;
  for (auto [j, w] : adj[i]) {
    if (j == p) {
      continue;
    }

    auto [ans_j, sum_of_products_j] = DFS(j, i);
    sum_of_products_j = (1ll * w * sum_of_products_j) % MOD;

    ans = (ans + ans_j + 1ll * sum_of_products * sum_of_products_j) % MOD;
    sum_of_products = (sum_of_products + sum_of_products_j) % MOD;
  }
  return {ans, sum_of_products};
}

int main() {
  int n;
  scanf("%d", &n);

  for (int e = 1; e < n; ++e) {
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  auto [ans, _] = DFS(1, 0);

  printf("%d\n", ans);

  return 0;
}