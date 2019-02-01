#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100005
#define B 3

ll a[B][N], dp[B][N], inf = LLONG_MAX / 10;

int main(){
  int n;
  ll maxS1 = -inf, maxS2 = -inf;

  scanf("%d", &n);

  for(int i = 0; i < B; i++)
    for(int j = 1; j <= n; j++)
      scanf("%lld", &a[i][j]);

  for(int j = 0; j < B; j++)
    for(int i = n + 1; i < N; i++)
      dp[j][i] = -inf;

  dp[2][n + 1] = 0;

  for(int i = n; i > 0; i--){
    maxS1 = a[0][i] + a[1][i] + a[2][i] + max(dp[2][i + 1], maxS1);
    maxS2 = a[0][i] + a[1][i] + a[2][i] + max(dp[0][i + 1], maxS2);
    dp[0][i] = max(maxS1, a[0][i] + max(dp[0][i + 1], a[1][i] + dp[1][i + 1]));
    dp[1][i] = a[1][i] + max(dp[1][i + 1], max(a[0][i] + dp[0][i + 1], a[2][i] + dp[2][i + 1]));
    dp[2][i] = max(maxS2, a[2][i] + max(dp[2][i + 1], a[1][i] + dp[1][i + 1]));
  }

  cout << dp[0][1] << '\n';

  return 0;
}
