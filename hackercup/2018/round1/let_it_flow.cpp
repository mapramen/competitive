#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define M 4
#define MOD 1000000007

char s[M][N];
int dp[M][N];

int Solve(){
  int n;

  scanf("%d", &n);

  for(int j = 1; j < M; ++j){
    scanf("%s", s[j]);
  }

  dp[1][0] = 1;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j < M; ++j){
      dp[j][i] = 0;

      if(j > 1 && s[j - 1][i - 1] == '.' && s[j][i - 1] == '.'){
        dp[j][i] = (dp[j][i] + dp[j - 1][i - 1]) % MOD;
      }

      if(j + 1 < M && s[j][i - 1] == '.' && s[j + 1][i - 1] == '.'){
        dp[j][i] = (dp[j][i] + dp[j + 1][i - 1]) % MOD;
      }
    }
  }

  return dp[M - 1][n];
}


int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }

  return 0;
}
