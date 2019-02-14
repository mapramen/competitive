#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int t;

  cin >> t;
  while(t--){
    ll x, y, p, q, ans;
    cin >> x >> y >> p >> q;
    if(p == 0){
      if(x == 0)
        ans = 0;
      else
        ans = -1;
    }
    else if(p == q){
      if(x == y)
        ans = 0;
      else
        ans = -1;
    }
    else{
      y -= x, q -= p;
      ll g1 = (x + p - 1) / p, g2 = (y + q - 1) / q;
      ll g = max(g1, g2);
      ans = g * p - x + g * q - y;
    }
    cout << ans << '\n';
  }
  
  return 0;
}
