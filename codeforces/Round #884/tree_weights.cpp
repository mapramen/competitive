#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001
#define LOGN 17

//----------------------------------------- LCA -----------------------------------------//
int startTime[N], finishTime[N], startTimeVertex[2 * N], eulerTour[2 * N], timer = 0;
int lg[2 * N], LCASparseTable[1 + LOGN][2 * N];

void BuildLCASparseTable(int n) {
  n = 2 * n;

  for (int i = 2; i < n; ++i) {
    lg[i] = 1 + lg[(i / 2)];
  }

  for (int i = 1; i <= n; ++i) {
    LCASparseTable[0][i] = startTime[eulerTour[i]];
  }

  for (int k = 1; k <= LOGN; ++k) {
    for (int i = 1, j = 1 + (1 << (k - 1)), m = n - (1 << k) + 1; i < m; ++i, ++j) {
      LCASparseTable[k][i] = min(LCASparseTable[k - 1][i], LCASparseTable[k - 1][j]);
    }
  }
}

int LCA(int i, int j) {
  i = startTime[i], j = startTime[j];

  if (i > j) {
    swap(i, j);
  }

  int k = lg[j - i + 1];
  int ans = startTimeVertex[min(LCASparseTable[k][i], LCASparseTable[k][j - (1 << k) + 1])];
  return ans;
}
//--------------------------------------- LCA Ends ---------------------------------------//

vector<vector<int>> adj(N);
pii edges[N];
ll d[N], b[N], a[N];

void DFS(int i, int p) {
  eulerTour[++timer] = i;
  startTime[i] = timer;
  startTimeVertex[startTime[i]] = i;

  for (int j : adj[i]) {
    if (j == p) {
      continue;
    }
    eulerTour[++timer] = i;
    DFS(j, i);
  }
}

void PreProcess(int n) {
  DFS(1, 0);
  BuildLCASparseTable(n);
}

bool Valid(int n) {
  PreProcess(n);

  for (int k = 0; k < 57; ++k) {
    int x = 0;
    ll m = (1ll << k);
    for (int i = 2; i <= n; ++i) {
      int lca = LCA(i - 1, i);
      ll di = (d[i] - (a[i - 1] + a[i] - 2 * a[lca]));

      if (di < 0 || di % m != 0) {
        return false;
      }

      di /= m;
      x ^= (di % 2);
      b[i] = x * m;
    }

    for (int i = 1; i <= n; ++i) {
      a[i] += b[i];
    }
  }

  for (int e = 1; e < n; ++e) {
    auto [i, j] = edges[e];
    if (startTime[i] > startTime[j]) {
      swap(i, j);
    }
    edges[e] = {i, j};
    if (a[j] <= a[i]) {
      return false;
    }
  }

  return true;
}

int main() {
  int n;
  scanf("%d", &n);

  for (int e = 1; e < n; ++e) {
    int i, j;
    scanf("%d%d", &i, &j);

    adj[i].push_back(j);
    adj[j].push_back(i);

    edges[e] = {i, j};
  }

  for (int i = 2; i <= n; ++i) {
    scanf("%lld", &d[i]);
  }

  if (!Valid(n)) {
    printf("-1\n");
    return 0;
  }

  for (int e = 1; e < n; ++e) {
    auto [i, j] = edges[e];
    printf("%lld\n", a[j] - a[i]);
  }

  return 0;
}