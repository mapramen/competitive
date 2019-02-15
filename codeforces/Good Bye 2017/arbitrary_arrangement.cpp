#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define MOD 1000000007

ll dp[N][N];

ll ModExp(ll a, ll n){
  ll y = 1;
  while(n){
    if(n % 2)
      y = (y * a) % MOD;
    a = (a * a) % MOD;
    n /= 2;
  }
  return y;
}

ll ModInv(ll a){
  return ModExp(a, MOD - 2);
}

int main(){
  ll k, p, q, invp, invq, a, b, c;

  cin >> k >> a >> b;

  c = ModInv(a + b);

  p = (a * c) % MOD;
  q = (b * c) % MOD;
  invp = ModInv(p), invq = ModInv(q);

  for(ll i = k; i > 0; --i){
    for(ll j = k; j > -1; --j){
      if(i + j >= k)
        dp[i][j] = (i + j + p * invq) % MOD;
      else
        dp[i][j] = (p * dp[i + 1][j] + q * dp[i][i + j]) % MOD;
    }
  }

  cout << dp[1][0] << '\n';

  return 0;
}
