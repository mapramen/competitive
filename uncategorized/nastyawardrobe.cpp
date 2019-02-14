#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 1000000007

ll ModExp(ll a, ll n){
  ll ans = 1;
  while(n){
    if(n % 2){
      ans = (ans * a) % MOD;
    }
    a = (a * a) % MOD;
    n /= 2;
  }
  return ans;
}

int main(){
  ll n, k;
  ll ans = 0;

  cin >> n >> k;

  if(n){
    ans = ModExp(2, k);
    n %= MOD;
    ans = (2 * ans * n + MOD - ans + 1) % MOD;
  }

  cout << ans << '\n';

  return 0;
}
