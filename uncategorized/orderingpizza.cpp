#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector< pii > v;

ll Cost(ll m){
  ll ans = 0;
  for(auto p : v){
    int b, c;
    tie(b, c) = p;
    if(c <= m){
      ans += 1ll * c * b;
      m -= c;
    }
    else{
      ans += 1ll * m * b;
      break;
    }
  }
  return ans;
}

ll BinarySearch(ll n, int m){
  ll x = 0, y = n;
  while(x < y){
    ll x1 = (x + y) / 2, x2 = min(y, x1 + 1);
    ll c1 = Cost(x1 * m), c2 = Cost(x2 * m);
    if(c1 <= c2)
      x = x2;
    else
      y = x1;
  }
  return max(0ll, Cost(x * m));
}

int main(){
  int n, m;
  ll s = 0, ans = 0;

  scanf("%d%d", &n, &m);

  while(n--){
    int c, a, b;
    scanf("%d%d%d", &c, &a, &b);
    ans += 1ll * a * c;
    v.PB(MP(b - a, c));
    s += c;
  }

  ll P = (s + m - 1) / m;

  v.PB(MP(0, (int)(m * P - s)));
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  ans += BinarySearch(P, m);

  printf("%lld\n", ans);

  return 0;
}
