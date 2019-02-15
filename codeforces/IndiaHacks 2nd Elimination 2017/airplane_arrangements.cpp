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
  a %= MOD;
  while(n){
    if(n % 2)
      ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    n /= 2;
  }
  return ans;
}

int main(){
  ll n, m, ans;
  cin >> n >> m;
  ans = ModExp(2 * (n + 1), m - 1);
  ans = (2 * (n - m + 1) * ans) % MOD;
  cout << ans << '\n';
  return 0;
}
