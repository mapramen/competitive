#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

vector<vector<int>> adj(N), subtrees(N);
int subtree_size[N], T[N];

void Update(int i, int x) {
  for (; i < N; i += (i & -i)) {
    T[i] += x;
  }
}

int Query(int i) {
  int ans = 0;
  for (i = min(N - 1, max(0, i)); i > 0; i -= (i & -i)) {
    ans += T[i];
  }
  return ans;
}

void SubtreeSizeDFS(int i, int p) {
  int ans = 1;

  for (int j : adj[i]) {
    if (j == p) {
      continue;
    }
    SubtreeSizeDFS(j, i);
    ans += subtree_size[j];
  }

  subtree_size[i] = ans;
}

ll ComputeAnsDFS(int k1, int k2, int i, int p, int d) {
  int heavy_child = 0;
  for (int j : adj[i]) {
    if (j == p || subtree_size[j] <= subtree_size[heavy_child]) {
      continue;
    }
    heavy_child = j;
  }

  ll ans = 0;
  for (int j : adj[i]) {
    if (j == p || j == heavy_child) {
      continue;
    }
    ans += ComputeAnsDFS(k1, k2, j, i, d + 1);
    for (int x : subtrees[j]) {
      Update(x, -1);
    }
  }

  subtrees[i].push_back(d);

  if (heavy_child != 0) {
    ans += ComputeAnsDFS(k1, k2, heavy_child, i, d + 1);
    swap(subtrees[i], subtrees[heavy_child]);
  } else {
    Update(d, 1);
  }

  for (int j : adj[i]) {
    if (j == p) {
      continue;
    }

    for (int x : subtrees[j]) {
      ans += Query(k2 + 2 * d - x) - Query(k1 - 1 + 2 * d - x);
    }

    for (int x : subtrees[j]) {
      Update(x, 1);
      subtrees[i].push_back(x);
    }
  }

  return ans;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  for (int e = 1; e < n; ++e) {
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  SubtreeSizeDFS(1, 0);

  printf("%lld\n", ComputeAnsDFS(k, k, 1, 0, 1));

  return 0;
}