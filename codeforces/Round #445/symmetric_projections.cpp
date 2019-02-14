#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector< pll > v;
ll n, xc = 0, yc = 0;

void PreProcess(){
  map< pll, int > M;

  for(auto p : v){
    ll x, y;
    tie(x, y) = p;
    x -= xc, y -= yc;

    if(x == 0 && y == 0)
      continue;

    pll q = MP(-x, -y);
    if(M[q] > 0)
      --M[q];
    else
      ++M[MP(x, y)];
  }

  v.clear();

  for(auto it : M){
    auto p = it.first;
    int x = it.second;
    while(x--)
      v.PB(p);
  }
}

int main(){
  scanf("%lld", &n);
  for(int i = 1; i <= n; ++i){
    ll x, y;
    scanf("%lld%lld", &x, &y);
    x *= 2 * n, y *= 2 * n;
    v.PB(MP(x, y));
    xc += (x / n), yc += (y / n);
  }

  PreProcess();

  n = v.size();

  if(n <= 1){
    printf("-1\n");
    return 0;
  }

  int ans = 0;
  ll x1, y1;

  tie(x1, y1) = v.back();

  set< pll > S;

  for(auto p : v){
    ll x2, y2, a, b;
    vector<ll> c;

    tie(x2, y2) = p;

    b = - (x1 + x2) / 2, a = (y1 + y2) / 2;

    if(a < 0)
      b *= -1, a *= -1;

    if(a == 0)
      b = abs(b);

    ll g = __gcd(abs(a), abs(b));
    a /= g, b /= g;

    if(S.find(MP(b, a)) != S.end())
      continue;

    S.insert(MP(b, a));

    for(auto q : v){
      ll x, y;

      tie(x, y) = q;
      ll z = a * x + b * y;

      if(z == 0)
        continue;

      c.PB(z);
    }

    sort(c.begin(), c.end());

    bool valid = 1;

    for(int i = 0, n = c.size(); i + i < n && valid == 1; ++i)
      valid &= (c[i] == - c[n - 1 - i]);

    ans += valid;
  }

  printf("%d\n", ans);

  return 0;
}
