#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 10001
#define M 111

vector<vector<int>> V(M), adj(N);
int parent[N];

void Reset(int n) {
  for (int i = 1; i <= n; ++i) {
    parent[i] = 0;
  }
}

int Find(int i) {
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j) {
  i = Find(i), j = Find(j);
  if (i == 0 || j == 0 || i == j) {
    return;
  }

  if (i > j) {
    swap(i, j);
  }

  parent[j] = i;
}

int main() {
  int n;
  scanf("%d", &n);

  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < n; ++y) {
      int i = x * n + y + 1;
      if (x != 0) {
        adj[i].push_back(i - n);
      }

      if (x != n - 1) {
        adj[i].push_back(i + n);
      }

      if (y != 0) {
        adj[i].push_back(i - 1);
      }

      if (y != n - 1) {
        adj[i].push_back(i + 1);
      }
    }
  }

  n *= n;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    V[x].push_back(i);
  }

  int ans = M;
  for (int x = 0; x < M; ++x) {
    Reset(n);
    for (int y = x; y < M && y < x + ans; ++y) {
      for (int i : V[y]) {
        parent[i] = i;
      }

      for (int i : V[y]) {
        for (int j : adj[i]) {
          Union(i, j);
        }
      }

      if (Find(n) == 1) {
        ans = min(ans, y - x);
        break;
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}