#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define MOD 1000000007

ll r[N];

ll ModExp(ll a, ll n){
  ll ans = 1 % MOD;
  while(n){
    if(n % 2)
      ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    n /= 2;
  }
  return ans;
}

ll ModInv(ll a){
  return ModExp(a, MOD - 2);
}

int main(){
  ll n, k, ans = 0;

  cin >> n >> k;

  if(k + 1 >= n){
    cout << "0\n";
    return 0;
  }

  for(ll i = 0; i <= k; ++i)
    r[i] = MOD - 1;

  for(ll i = k + 1, s = (MOD - k) % MOD; i < n; ++i){
    r[i] = (s * ModInv(i)) % MOD;
    s = (s + r[i] - r[i - k] + MOD) % MOD;
    ans = (ans + 1 + r[i]) % MOD;
  }

  for(ll i = 1; i < n; ++i)
    ans = (i * ans) % MOD;

  cout << ans << '\n';

  return 0;
}
