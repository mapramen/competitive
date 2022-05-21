#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

char s[N][N];
int dp[2 * N][N][N];

int Solve(){
  int n, m;
  scanf("%d%d", &m, &n);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  for(int k = 0; k <= n + m; ++k){
    for(int i = 0; i <= n; ++i){
      for(int j = 0; j <= n; ++j){
        dp[k][i][j] = -2e6;
      }
    }
  }

  dp[1][1][1] = 0;
  for(int k = 2; k <= n + m; ++k){
    for(int i = 1; i <= min(k, n); ++i){
      for(int j = 1; j <= min(k, n); ++j){
        char c1 = s[i - 1][k - i - 1], c2 = s[j - 1][k - j - 1];
        if(c1 == '#' || c2 == '#'){
          continue;
        }
        dp[k][i][j] = max(max(dp[k - 1][i - 1][j - 1], dp[k - 1][i - 1][j]), max(dp[k - 1][i][j - 1], dp[k - 1][i][j]))
                      + (c1 == '*') + (c2 == '*') - (c1 == '*' && i == j);
      }
    }
  }

  return dp[n + m][n][n];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}