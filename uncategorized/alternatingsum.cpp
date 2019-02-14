#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define MOD 1000000009

char s[N];

ll ModExp(ll a, ll n){
  a = (MOD + a % MOD) % MOD;
  ll ans = 1;
  a %= MOD;
  while(n){
    if(n % 2)
      ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    n /= 2;
  }
  return ans;
}

ll ModInv(ll a){
  a = (MOD + a % MOD) % MOD;
  return ModExp(a, MOD - 2);
}

int main(){
  ll n, a, b, k, m;

  cin >> n >> a >> b >> k;

  scanf("%s", s);

  m = (n + 1) / k;

  ll S = 0, inva = ModInv(a), r = (b * inva) % MOD;

  for(ll i = 0, t = 1; i < k; ++i, t = (t * r) % MOD){
    if(s[i] == '+')
      S += t;
    else
      S -= t;
    S = (MOD + S) % MOD;
  }

  S = (S * ModExp(a, n)) % MOD;

  r = ModExp(r, k);

  if(r == 1)
    S = (m * S) % MOD;
  else{
    S = (S * (ModExp(r, m) + MOD - 1)) % MOD;
    S = (S * (ModInv(MOD + r - 1))) % MOD;
  }

  cout << S << '\n';

  return 0;
}
