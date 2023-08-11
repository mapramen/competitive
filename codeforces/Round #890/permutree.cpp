#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000001

vector<vector<int>> adj(N);
int subtree_size[N];
ll dp[N];

void NormalizeKnapsack(map<int, int>& C) {
  for (int i = 1; i <= C.rbegin()->first; ++i) {
    auto it = C.lower_bound(i);
    i = it->first;
    int z = max(0, it->second - 1) / 2;
    if (z != 0) {
      (it->second) -= 2 * z;
      C[2 * i] += z;
    }
  }
}

template <int len = 1>
ll Compute(int m, map<int, int>& C) {
  if (m >= 2 * len) {
    return Compute<std::min(2 * len, N)>(m, C);
  }

  int hs = C.rbegin()->first;
  if (2 * hs >= m) {
    return 1ll * hs * (m - hs);
  }

  bitset<len> bs;

  bs.set(0);
  for (auto [k, v] : C) {
    while (v--) {
      bs |= (bs << k);
    }
  }

  for (int k = m / 2; k > -1; --k) {
    if (bs.test(k)) {
      return 1ll * k * (m - k);
    }
  }

  return 0;
}

void DFS(int i) {
  subtree_size[i] = 1;
  dp[i] = 0;

  map<int, int> C;
  for (int j : adj[i]) {
    DFS(j);
    subtree_size[i] += subtree_size[j];
    dp[i] += dp[j];
    ++C[subtree_size[j]];
  }

  if (adj[i].size() > 1) {
    NormalizeKnapsack(C);
    dp[i] += Compute<1>(subtree_size[i] - 1, C);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 2; i <= n; ++i) {
    int p;
    scanf("%d", &p);
    adj[p].push_back(i);
  }

  DFS(1);

  printf("%lld\n", dp[1]);

  return 0;
}