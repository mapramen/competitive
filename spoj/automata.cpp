#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001
#define M 31

bool dp[2][M];
char A[M], B[N];

bool DP(int i, int j){
  char a = A[j - 1], b = B[i - 1];

  if(isalpha(a)){
    return a == b && dp[0][j - 1];
  }

  if(a == '?'){
    return dp[0][j - 1] || dp[1][j - 1];
  }

  return dp[0][j] || dp[1][j - 1];
}

bool Solve(){
  scanf("%s%s", A, B);

  int m = strlen(A), n = strlen(B);

  dp[0][0] = true;
  for(int j = 1; j <= m; ++j){
    dp[0][j] = false;
  }

  for(int i = 1; i <= n; ++i){
    dp[1][0] = false;

    for(int j = 1; j <= m; ++j){
      dp[1][j] = DP(i, j);
    }

    for(int j = 0; j <= m; ++j){
      dp[0][j] = dp[1][j];
    }
  }

  return dp[1][m];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "Yes" : "No");
  }
  return 0;
}