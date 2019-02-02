#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 31

ll c[B];

ll Cost(ll n){
  ll ans = 0;
  for(ll i = 0; i < B; ++i)
    ans += ((n & (1 << i)) != 0) * c[i];
  return ans;
}

int main(){
  ll n, m;

  cin >> m >> n;

  for(int i = 0; i < B; ++i)
    c[i] = LLONG_MAX;

  for(int i = 0; i < m; ++i)
    cin >> c[i];

  for(int i = 1; i < B; ++i)
    c[i] = min(c[i], c[i - 1] + c[i - 1]);

  ll ans = c[B - 1];
  while(n <= (1 << (B - 1))){
    ans = min(ans, Cost(n));
    n += (n & -n);
  }

  cout << ans << '\n';

  return 0;
}
