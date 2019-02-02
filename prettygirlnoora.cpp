#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5000001
#define MOD 1000000007

ll dp[N];

int main(){
  int t, l, r, ans = 0;

  cin >> t >> l >> r;

  for(int i = 1; i <= r; i++)
    dp[i] = 1ll * i * (i - 1) / 2;

  for(int i = 2; i <= r; i++)
    for(int j = i + i, x = 2; j <= r; j += i, x++)
      dp[j] = min(dp[j], dp[i] + 1ll * j * (x - 1) / 2);

  for(int i = r; i >= l; i--)
    ans = (1ll * t * ans + dp[i]) % MOD;

  cout << ans << '\n';

  return 0;
}
