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
    ll s, a, b, c;
    cin >> s >> a >> b >> c;
    ll x = s / c;
    ll y = b * (x / a);
    ll ans = x + y;
    cout << ans << '\n';
  }
  return 0;
}
