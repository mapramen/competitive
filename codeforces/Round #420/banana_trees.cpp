#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll m, b, ans = 0;

  cin >> m >> b;
  for(ll x = 0, y = b; x <= m * b; x++){
    for( ; m * y + x - m * b > 0; y--);
    ll ansx = (x + 1) * (y + 1) * (x + y) / 2;
    ans = max(ans, ansx);
  }

  cout << ans << '\n';

  return 0;
}
