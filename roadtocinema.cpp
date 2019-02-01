#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200010

ll g[N];
pll b[N];

bool Check(ll c, ll n, ll t){
  ll tx = 0;

  for(ll i = 1; i <= n; i++){
    ll d = g[i];
    if(d > c)
      return 0;
    else{
      ll y = min(c - d, d);
      ll x = d - y;
      tx += (2 * x + y);
    }
  }

  return (tx <= t);
}

int main(){
  ll n, k, s, t, i, j, ans = -1;

  scanf("%lld%lld%lld%lld", &n, &k, &s, &t);

  for(i = 1; i <= n; i++)
    scanf("%lld%lld", &b[i].second, &b[i].first);

  for(i = 1; i <= k; i++)
    scanf("%lld", &g[i]);
  g[k + 1] = s;

  sort(b + 1, b + n + 1);
  for(i = n - 1; i > 0; i--)
    b[i].second = min(b[i].second, b[i + 1].second);

  k++;
  sort(g, g + k + 1);
  for(i = k; i > 0; i--)
    g[i] -= g[i - 1];

  for(ll x = 1, y = n; x <= y; ){
    ll mid = x + (y - x) / 2;

    if(Check(b[mid].first, k, t)){
      ans = b[mid].second;
      y = mid - 1;
    }
    else
      x = mid + 1;
  }

  printf("%lld\n", ans);

  return 0;
}
