#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5001

char s[N];
int dp[N][N];

int main(){
  int n;
  scanf("%d%s", &n, s);

  for(int i = 1; i <= n; ++i){
    dp[i][i] = 0;
  }

  for(int i = 1, j = 2; j <= n; ++i, ++j){
    dp[i][j] = s[i - 1] != s[j - 1];
  }

  for(int l = 3; l <= n; ++l){
    for(int i = 1, j = l; j <= n; ++i, ++j){
      dp[i][j] = s[i - 1] == s[j - 1] ? dp[i + 1][j - 1] : 1 + min(dp[i][j - 1], dp[i + 1][j]);
    }
  }

  printf("%d\n", dp[1][n]);
  
  return 0;
}