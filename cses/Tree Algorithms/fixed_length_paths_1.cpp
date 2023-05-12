#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

vector<vector<int>> adj(N);
int subtreeSize[N];
bool isCentroid[N];
vector<int> T, a;

void Update(int i, int x) {
  for (; i < T.size(); i += (i & -i)) {
    T[i] += x;
  }
}

int Query(int i) {
  int ans = 0;
  for (i = min((int)T.size() - 1, max(0, i)); i > 0; i -= (i & -i)) {
    ans += T[i];
  }
  return ans;
}

int SubtreeSizeDFS(int i, int p) {
  int ans = 1;

  for (int j : adj[i]) {
    if (isCentroid[j] || j == p) {
      continue;
    }
    ans += SubtreeSizeDFS(j, i);
  }

  subtreeSize[i] = ans;
  return ans;
}

int FindCentroidDFS(int i, int p, int s) {
  for (int j : adj[i]) {
    if (!isCentroid[j] && j != p && 2 * subtreeSize[j] > s) {
      return FindCentroidDFS(j, i, s);
    }
  }
  return i;
}

void FillSubtreeDFS(int i, int p, int d) {
  if (isCentroid[i]) {
    return;
  }

  a.push_back(d);
  for (int j : adj[i]) {
    if (j == p) {
      continue;
    }
    FillSubtreeDFS(j, i, d + 1);
  }
}

ll ComputeAns(int k1, int k2, int i) {
  ll ans = 0;
  for (int j : adj[i]) {
    a.clear();
    FillSubtreeDFS(j, i, 1);
    for (int d : a) {
      ans += Query(k2 - d) - Query(k1 - d - 1);
    }

    for (int d : a) {
      Update(d, 1);
    }
  }
  ans += Query(k2) - Query(k1 - 1);
  T.clear();
  return ans;
}

ll CentroidDecompositionDFS(int k1, int k2, int i) {
  SubtreeSizeDFS(i, 0);

  i = FindCentroidDFS(i, 0, subtreeSize[i]);
  isCentroid[i] = true;

  T.resize(subtreeSize[i]);
  ll ans = ComputeAns(k1, k2, i);
  for (int j : adj[i]) {
    if (isCentroid[j]) {
      continue;
    }
    ans += CentroidDecompositionDFS(k1, k2, j);
  }

  isCentroid[i] = false;
  return ans;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  for (int x = 1; x < n; ++x) {
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  printf("%lld\n", CentroidDecompositionDFS(k, k, 1));

  return 0;
}