#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 201
#define M 200 * 25 + 1

int dp[N][M];

int main(){
  int n, k;

  cin >> n >> k;

  for(int i = 0; i <= k; ++i)
    for(int j = 0; j < M; ++j)
      dp[i][j] = INT_MIN;

  dp[0][0] = 0;

  for(int tx = 1; tx <= n; ++tx){
    ll a;
    int x = 0, y = 0;

    cin >> a;

    while(a % 2 == 0)
      ++x, a /= 2;

    while(a % 5 == 0)
      ++y, a /= 5;

    for(int i = k; i > 0; --i)
      for(int j = M - 1; j >= y; --j)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - y] + x);
  }

  int ans = 0;
  for(int j = 0; j < M; ++j)
    ans = max(ans, min(j, dp[k][j]));

  cout << ans << '\n';

  return 0;
}
