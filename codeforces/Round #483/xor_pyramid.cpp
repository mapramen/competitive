#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001

int dp[N][N];

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &dp[i][i]);

  for(int k = 2; k <= n; ++k)
    for(int i = 1, j = k; j <= n; ++i, ++j)
      dp[i][j] = (dp[i][j - 1] ^ dp[i + 1][j]);

  for(int k = 2; k <= n; ++k)
    for(int i = 1, j = k; j <= n; ++i, ++j)
      dp[i][j] = max(dp[i][j], max(dp[i][j - 1], dp[i + 1][j]));

  int q;
  scanf("%d", &q);
  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    printf("%d\n", dp[i][j]);
  }

  return 0;
}
