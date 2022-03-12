#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

int a[N], dp[N][N];

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    dp[i][i] = a[i];
  }

  for(int k = 2; k <= n; ++k){
    for(int i = 1, j = k; j <= n; ++i, ++j){
      int ans;

      if(k % 2 == 1){
        ans = a[j] > a[i] ? a[j] - dp[i][j - 1] : a[i] - dp[i + 1][j];
      }
      else{
        ans = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
      }

      dp[i][j] = ans;
    }
  }

  return dp[1][n];
}

int main(){
  for(int k = 1; ; ++k){
    printf("In game %d, the greedy strategy might lose by as many as %d points.\n", k, Solve());
  }
  return 0;
}