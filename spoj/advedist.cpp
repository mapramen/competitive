#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define M 26

char A[N], B[N];
int ia[M];
int dp[N][N];

int Solve(){
  scanf("%s%s", A, B);

  if(A[0] == '*'){
    exit(0);
  }

  int n = strlen(A), m = strlen(B);

  for(int k = 0; k < M; ++k){
    ia[k] = 0;
  }

  for(int i = 0; i <= n; ++i){
    dp[i][0] = i;
  }

  for(int j = 0; j <= m; ++j){
    dp[0][j] = j;
  }

  for(int i = 1; i <= n; ++i){
    int l = 0;
    for(int j = 1; j <= m; ++j){
      int k = ia[B[j - 1] - 'a'];
      int ans = n + m;

      ans = min(ans, dp[i - 1][j - 1] + (A[i - 1] != B[j - 1]));
      ans = min(ans, dp[i][j - 1] + 1);
      ans = min(ans, dp[i - 1][j] + 1);

      if(k != 0 && l != 0){
        ans = min(ans, dp[k - 1][l - 1] + (i - k - 1) + 1 + (j - l - 1));
      }

      if(B[j - 1] == A[i - 1]){
        l = j;
      }

      dp[i][j] = ans;
    }
    ia[A[i - 1] - 'a'] = i;
  }

  return dp[n][m];
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}