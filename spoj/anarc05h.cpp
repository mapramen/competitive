#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 26
#define M (10 * N)

char s[N];
int dp[N][M];

int Solve(){
  scanf("%s", s);

  if(s[0] == 'b'){
    exit(0);
  }

  int n = strlen(s), m = 9 * n + 1;
  for(int x = 0; x <= m; ++x){
    dp[0][x] = 1;
  }

  for(int i = 1; i <= n; ++i){
    for(int x = 0; x <= m; ++x){
      dp[i][x] = 0;
    }

    for(int j = i, x = 0; j != 0; --j){
      x += s[j - 1] - '0';
      dp[i][x] += dp[j - 1][x];
    }

    for(int x = 1; x <= m; ++x){
      dp[i][x] += dp[i][x - 1];
    }
  }

  return dp[n][m];
}

int main(){
  for(int k = 1; ; ++k){
    printf("%d. %d\n", k, Solve());
  }
  return 0;
}