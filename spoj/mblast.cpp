#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001

char A[N], B[N];
int dp[N][N];

int main(){
  int k;
  scanf("%s%s%d", A, B, &k);

  int n = strlen(A), m = strlen(B);

  for(int i = 1; i <= n; ++i){
    dp[i][0] = i * k;
  }

  for(int j = 1; j <= m; ++j){
    dp[0][j] = j * k;
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      dp[i][j] = min(abs(A[i - 1] - B[j - 1]) + dp[i - 1][j - 1], k + min(dp[i - 1][j], dp[i][j - 1]));
    }
  }

  printf("%d\n", dp[n][m]);

  return 0;
}