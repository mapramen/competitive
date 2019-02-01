#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll n, k, M, D, ans = 0;

  cin >> n >> k >> M >> D;

  for(ll d = D; d > 0; --d){
    ll x1 = max(1ll, (n / d) / k);
    ll x2 = 0;
    if(d == 1 || ((n - 1) / (d - 1)) / k > 0)
      x2 = min(M, n / ((d - 1) * k + 1));
    if(x1 <= x2)
      ans = max(ans, d * x2);
  }

  cout << ans << '\n';

  return 0;
}
