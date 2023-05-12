#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

vector<vector<int>> adj(N);
int subtreeSize[N];

void DFS(int i, int parent) {
  int sz = 1;

  for (int j : adj[i]) {
    if (j == parent) {
      continue;
    }
    DFS(j, i);
    sz += subtreeSize[j];
  }

  subtreeSize[i] = sz;
}

int FindCentroidDFS(int i, int p, int s) {
  for (int j : adj[i]) {
    if (j != p && 2 * subtreeSize[j] > s) {
      return FindCentroidDFS(j, i, s);
    }
  }
  return i;
}

int main() {
  int n;
  scanf("%d", &n);

  for (int x = 1; x < n; ++x) {
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);

  printf("%d\n", FindCentroidDFS(1, 0, n));

  return 0;
}