#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

char A[N], B[N];
int dp[N][N];

int Solve(){
  scanf("%s", A);
  if(A[0] == '#'){
    exit(0);
  }

  scanf("%s", B);

  int n = strlen(A), m = strlen(B);
  
  for(int j = 0; j <= m; ++j){
    dp[0][j] = 30 * j;
  }

  for(int i = 1; i <= n; ++i){
    dp[i][0] = 15 * i;
    for(int j = 1; j <= m; ++j){
      dp[i][j] = min(A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] : INT_MAX, min(30 + dp[i][j - 1], 15 + dp[i - 1][j]));
    }
  }

  return dp[n][m];
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}