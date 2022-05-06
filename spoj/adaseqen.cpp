#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001
#define K 26

char A[N], B[N];
int c[K], dp[N][N];

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int k = 0; k < K; ++k){
    scanf("%d", &c[k]);
  }

  scanf("%s%s", A, B);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      int ans = max(dp[i - 1][j], dp[i][j - 1]);
      if(A[i - 1] == B[j - 1]){
        ans = max(ans, c[A[i - 1] - 'a'] + dp[i - 1][j - 1]);
      }
      dp[i][j] = ans;
    }
  }

  printf("%d\n", dp[n][m]);

  return 0;
}