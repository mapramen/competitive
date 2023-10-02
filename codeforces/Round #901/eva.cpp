#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 5001

vector<vector<int>> adj(N);
double p[N][N], dp[N];

void Initialize() {
  for (int i = 1; i < N; ++i) {
    p[i][1] = 1.0 / i;
    for (int j = 2; j <= i; ++j) {
      p[i][j] = ((i - j) * p[i - 2][j - 1] + (j - 2) * p[i - 2][j - 2]) / i;
    }
  }
}

void Reset(int n) {
  for (int i = 0; i <= n; ++i) {
    adj[i].clear();
    dp[i] = 0;
  }
}

double Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  Reset(n);

  while (m--) {
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
  }

  dp[n] = 1;
  for (int i = n - 1; i > 0; --i) {
    vector<double> a;
    for (int j : adj[i]) {
      a.push_back(dp[j]);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    double ans = 0;
    for (int j = 1, k = adj[i].size(); j <= k; ++j) {
      ans += p[k][j] * a[j - 1];
    }
    dp[i] = ans;
  }

  return dp[1];
}

int main() {
  Initialize();
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%.15lf\n", Solve());
  }
  return 0;
}