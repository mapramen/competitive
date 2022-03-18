#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 20

char s[2 * N];
int dp[2 * N][N];

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int i = 1; i <= 2 * n; ++i){
    s[i] = '?';
  }

  while(k--){
    int i;
    scanf("%d", &i);
    s[i] = '[';
  }

  dp[0][0] = 1;
  for(int i = 1; i <= 2 * n; ++i){
    dp[i][0] = 0;
    for(int j = 1; j <= n; ++j){
      dp[i][j] = dp[i - 1][j - 1];
    }

    if(s[i] == '?'){
      for(int j = 0; j < n; ++j){
        dp[i][j] += dp[i - 1][j + 1];
      }
    }
  }

  return dp[2 * n][0];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}