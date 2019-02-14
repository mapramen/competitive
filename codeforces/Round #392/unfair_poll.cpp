#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

ll c[N][N];

int main(){
  ll n, m, k, x, y, q, d, mn, mx, cs;

  cin >> n >> m >> k >> x >> y;

  if(n == 1)
    d = m;
  else
    d = 2 * (n - 1) * m;

  q = k / d;
  k %= d;

  for(ll j = 1; j <= m; j++)
    c[1][j] = q;

  for(ll i = 2; i < n; i++)
    for(ll j = 1; j <= m; j++)
      c[i][j] = 2 * q;

  for(ll j = 1; j <= m && n != 1; j++)
    c[n][j] = q;

  for(ll i = 1; i <= n && k > 0; i++)
    for(ll j = 1; j <= m && k > 0; j++, k--)
      c[i][j]++;

  for(ll i = n - 1; i > 0 && k > 0; i--)
    for(ll j = 1; j <= m && k > 0; j++, k--)
      c[i][j]++;

  mn = LLONG_MAX, mx = LLONG_MIN;

  for(ll i = 1; i <= n; i++)
    for(ll j = 1; j <= m; j++)
      mn = min(mn, c[i][j]), mx = max(mx, c[i][j]);

  cs = c[x][y];

  printf("%lld %lld %lld\n", mx, mn, cs);

  return 0;
}
