#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll n, k;

  cin >> n >> k;

  ll ans = 0;

  for(int i = 59; i > -1; --i){
    if(ans + (1ll << i) <= n)
      ans += (1ll << i);
  }

  ll m = 1;
  for( ; m <= n; m *= 2);
  --m;

  if(k == 1)
    cout << ans << '\n';
  else
    cout << m << '\n';

  return 0;
}
