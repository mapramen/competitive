#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

ll n, s, MOD, dp[N], p[N];

ll Check(int m, int i, int j){
  if(j > m  || (i == 1 && j == 1)){
    return 0ll;
  }
  else{
    return (dp[i] * p[m - j]) % MOD;
  }
}

int main(){
  cin >> n >> s >> MOD;

  p[0] = 1;
  for(int i = 1; i <= n; ++i){
    p[i] = (s * p[i - 1]) % MOD;
  }

  dp[1] = s;
  for(int i = 2; i <= n; ++i){
    ll ans = 0;
    for(int j = 1; j <= i; ++j){
      ans = (ans + Check(i, j, 2 * j - 1) + Check(i, j, 2 * j)) % MOD;
    }
    dp[i] = (p[i] + MOD - ans) % MOD;
  }

  cout << dp[n] << '\n';

  return 0;
}
