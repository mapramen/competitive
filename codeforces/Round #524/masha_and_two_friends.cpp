#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

ll ColorCount(ll x1, ll y1, ll x2, ll y2, bool color){
  if(x1 > x2 || y1 > y2){
    return 0ll;
  }

  ll t = (x2 - x1 + 1) * (y2 - y1 + 1);
  ll white = (t / 2) + (t % 2), black = t - white;

  bool baseColor = (x1 + y1) % 2;

  ll ans = (color == baseColor) ? white : black;

  return ans;
}

int main(){
  int q;

  cin >> q;
  while(q--){
    ll n, m, x1, x2, x3, x4, y1, y2, y3, y4;

    cin >> m >> n;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    ll white = ColorCount(1, 1, n, m, 0), black = ColorCount(1, 1, n, m, 1);

    ll c = ColorCount(x1, y1, x2, y2, 1) - ColorCount(max(x1, x3), max(y1, y3), min(x2, x4), min(y2, y4), 1);
    white += c;
    black -= c;

    c = ColorCount(x3, y3, x4, y4, 0);
    white -= c;
    black += c;

    cout << white << ' ' << black << '\n';
  }

  return 0;
}
