#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  ll n, k;

  cin >> n >> k;

  ll x = 1, y = n;

  while(true){
    x = max(1ll, x - k), y = min(n, y + k);
    ll m, l, r;

    if(y - x + 1 > 5 * k){
      m = (x + y) / 2;
      l = x, r = m;
    }
    else{
      m = x + uniform_int_distribution<int>(0, (int)(y - x))(rng);
      l = m, r = m;
    }

    cout << l << ' ' << r << '\n';
    fflush(stdout);

    string s;
    cin >> s;

    if(s == "No"){
      if(y - x + 1 > 5 * k){
        x = m + 1;
      }
    }
    else{
      if(l == r){
        break;
      }
      else{
        if(y - x + 1 > 5 * k){
          y = m;
        }
      }
    }
  }

  return 0;
}
