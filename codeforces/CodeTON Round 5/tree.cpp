#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 5001

vector<vector<int>> adj(N);
int d[N], ans[N];
queue<int> Q;

void CheckAndPush(int i, int di) {
  if (d[i] == INT_MAX) {
    d[i] = di;
    Q.push(i);
  }
}

void UpdateAns(int n, int i) {
  for (int i = 1; i <= n; ++i) {
    d[i] = INT_MAX;
  }

  CheckAndPush(i, 0);

  int sum_depth = 0, k = 0;
  while (!Q.empty()) {
    int i = Q.front();
    Q.pop();

    sum_depth += d[i];
    for (int j : adj[i]) {
      CheckAndPush(j, d[i] + 1);
    }

    ++k;
    ans[k] = max(ans[k], (n - 1) * k - 2 * sum_depth);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  for (int e = 1; e < n; ++e) {
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  for (int i = 1; i <= n; ++i) {
    UpdateAns(n, i);
  }

  for (int k = 0; k <= n; ++k) {
    printf("%d ", ans[k]);
  }
  printf("\n");

  return 0;
}