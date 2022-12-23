#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

pii a[N];
double dp[N][N];

double Dis(int i, int j){
  int dx = a[i].first - a[j].first;
  int dy = a[i].second - a[j].second;
  return sqrt(1ll * dx * dx + 1ll * dy * dy);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i].first, &a[i].second);
  }
  sort(a + 1, a + n + 1);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= i; ++j){
      dp[i][j] = INT_MAX;
    }
  }

  dp[1][1] = 0;
  for(int i = 2; i <= n; ++i){
    for(int j = 1; j < i; ++j){
      dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + Dis(i, j));
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + Dis(i, i - 1));
    }
  }

  double ans = INT_MAX;
  for(int j = 1; j < n; ++j){
    ans = min(ans, dp[n][j] + Dis(n, j));
  }

  printf("%.2lf\n", ans);

  return 0;
}