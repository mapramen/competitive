#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll n, m;

  cin >> n >> m;

  ll x = max(0ll, n - 2 * m), y = 0;

  for( ; y * (y - 1) / 2 < m; ++y);

  y = n - y;

  cout << x << ' ' << y << '\n';

  return 0;
}
