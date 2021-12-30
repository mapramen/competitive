#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 2001

int D, c[N][N], dp[N][N];

int Weight(int i, int j){
  return D * abs(i - j) + c[i][j];
}

int Solve(){
  int n;
  scanf("%d%d", &n, &D);

  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      int x;
      scanf("%d", &x);
      c[i][j] = x, c[j][i] = x;
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      dp[i][j] = INT_MAX / 2;
    }
  }

  dp[1][1] = 0;
  for(int i = 2; i < n; ++i){
    for(int j = 1; j < i; ++j){
      dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + Weight(j, i));
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + Weight(i - 1, i));
    }
  }

  int ans = INT_MAX;
  for(int i = 1; i < n; ++i){
    ans = min(ans, dp[n - 1][i] + Weight(n, i) + Weight(n, n - 1));
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}