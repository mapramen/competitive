#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001
#define MOD 1000000007

int parent[N], sz[N];

void Reset(int n) {
  for (int i = 1; i <= n; ++i) {
    parent[i] = i, sz[i] = 0;
  }
}

int Find(int i) {
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j) {
  i = Find(i), j = Find(j);
  if (i == j) {
    ++sz[i];
    return;
  }

  if (i > j) {
    swap(i, j);
  }

  parent[j] = i;
  sz[i] += sz[j];
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  Reset(n);

  while (m--) {
    int i, j;
    scanf("%d%d", &i, &j);
    Union(i, j);
  }

  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    if (Find(i) != i) {
      continue;
    }

    for (int k = 1; k <= sz[i]; ++k) {
      ans = (ans * 2) % MOD;
    }
  }

  printf("%d\n", ans);

  return 0;
}