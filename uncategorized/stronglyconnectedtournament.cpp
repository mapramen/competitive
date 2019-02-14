#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2001
#define MOD 998244353

ll P[N], Q[N], cp[N][N], strong[N], dp[N];

ll ModExp(int a, int n){
  ll x = a, y = 1;
  while(n){
    if(n % 2 == 1)
      y = (x * y) % MOD;
    x = (x * x) % MOD;
    n /= 2;
  }
  return y;
}

ll ModInv(int a){
  return ModExp(a, MOD - 2);
}

int main(){
  int n, a, b;

  cin >> n >> a >> b;

  ll p = (a * ModInv(b)) % MOD, q = (MOD + 1 - p) % MOD;

  P[0] = Q[0] = 1;
  for(int i = 1; i <= n; ++i){
    P[i] = (p * P[i - 1]) % MOD;
    Q[i] = (q * Q[i - 1]) % MOD;
  }

  for(int i = 0; i <= n; ++i){
    cp[i][0] = 1;
    for(int j = 1; j <= i; ++j)
      cp[i][j] = (P[i - j] * cp[i - 1][j - 1] + Q[j] * cp[i - 1][j]) % MOD;
  }

  for(int i = 1; i <= n; ++i){
    ll x = 0;
    for(int j = 1; j < i; ++j)
      x = (x + strong[j] * cp[i][j]) % MOD;
    strong[i] = (MOD + 1 - x) % MOD;
  }

  dp[0] = dp[1] = 0;
  for(int i = 2; i <= n; ++i){
    ll ans = 0;
    for(int j = 1; j < i; ++j){
      ll x = (strong[j] * cp[i][j]) % MOD;
      ll y = (j * (i - j) + j * (j - 1) / 2 + dp[j] + dp[i - j]) % MOD;
      ans = (ans + x * y) % MOD;
    }

    ll c = strong[i];
    ans = (ans + c * (i * (i - 1) / 2)) % MOD;
    c = (MOD + 1 - c) % MOD;
    ans = (ans * ModInv((int)c)) % MOD;
    dp[i] = ans;
  }

  cout << dp[n] << '\n';

  return 0;
}
