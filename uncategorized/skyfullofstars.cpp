#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 3
#define N 1000001
#define MOD 998244353

ll fact[N], invFact[N];

ll ModExp(ll a, ll n){
  a = (MOD + (a % MOD)) % MOD;
  ll y = 1;
  while(n){
    if(n % 2){
      y = (y * a) % MOD;
    }
    a = (a * a) % MOD;
    n /= 2;
  }
  return y;
}

ll ModInv(ll a){
  return ModExp(a, MOD - 2);
}

void Initialise(){
  fact[0] = 1;
  for(int i = 1; i < N; ++i){
    fact[i] = (i * fact[i - 1]) % MOD;
  }

  invFact[N - 1] = ModInv(fact[N - 1]);
  for(int i = N - 2; i > -1; --i){
    invFact[i] = ((i + 1) * invFact[i + 1]) % MOD;
  }
}

ll nCr(int n, int r){
  if(r < 0 || n < 0 || n < r){
    return 0ll;
  }
  else{
    ll p = fact[n];
    ll q = (invFact[r] * invFact[n - r]) % MOD;
    return (p * q) % MOD;
  }
}

int main(){
  int n;

  cin >> n;

  Initialise();

  ll ans = 0, b = 1;
  for(int i = 0, k = -1; i < n; ++i, b = (B * b) % MOD, k = -k){
    ans = (ans + k * nCr(n, i) * ModExp(1 - b, n)) % MOD;
  }

  ans = 2 * (ModExp(b, n) - ModExp(b - B, n)) + B * ans - B * (ModExp(b, n) - ModExp(b - 1, n));
  ans = (MOD + (ans % MOD)) % MOD;

  cout << ans << '\n';

  return 0;
}
