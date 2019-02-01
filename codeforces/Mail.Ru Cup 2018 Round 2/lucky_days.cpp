#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

ll NearestOffset(ll x, ll g){
  return (g + (x % g)) % g;
}

ll Solve(ll la, ll ra, ll ta, ll lb, ll rb, ll tb){
  ll g = __gcd(ta, tb);
  ll x = NearestOffset(lb - la, g);
  return max(0ll, min(x + rb - lb, ra - la) - max(0ll, x) + 1);
}

int main(){
  ll la, ra, ta, lb, rb, tb;

  cin >> la >> ra >> ta >> lb >> rb >> tb;

  cout << max(Solve(la, ra, ta, lb, rb, tb), Solve(lb, rb, tb, la, ra, ta)) << '\n';

  return 0;
}
