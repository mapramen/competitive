#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll a, b, x, y;

  cin >> a >> b >> x >> y;

  ll g = __gcd(x, y);
  x /= g, y /= g;

  ll ans = min(a / x, b / y);

  cout << ans << '\n';

  return 0;
}
