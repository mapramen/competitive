#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

ll gcd(ll a, ll b){
  if(b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main(){
  ll a, b, ans = 0;
  vector<ll> v;

  cin >> a >> b;

  for(ll i = 1; i * i <= a; ++i){
    if(a % i == 0)
      v.PB(i), v.PB(a / i);
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  while(b != 0){
    ll g = gcd(a, b), bx = 0;
    for(auto d : v){
      if(d % g > 0 || d == g)
        continue;
      bx = max(bx, ((b - 1) / d) * d);
    }
    ans += (b - bx) / g;
    b = bx;
  }

  cout << ans << '\n';

  return 0;
}
