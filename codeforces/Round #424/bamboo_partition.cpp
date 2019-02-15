#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

ll n, k, a[N];
vector<ll> v;

void AddIntervals(ll a){
  ll r;
  for(ll i = 1; ; i++){
    r = a / i;

    if(r * r >= a)
      v.PB(r);
    else
      break;
  }

  for( ; r > 0; r--)
    v.PB(r);
}

bool Check(ll m){
  ll s = n * m;
  for(int i = 1; i <= n; i++)
    if(a[i] % m == 0)
      s -= m;
    else
      s -= (a[i] % m);
  return (s <= k);
}

ll BinarySearch(ll l, ll r){
  ll x = l, y = r, z = -1;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Check(mid))
      z = mid, x = mid + 1;
    else
      y = mid - 1;
  }
  return z;
}

int main(){
  ll s = 0, m = 0, ans = 0;

  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    s += a[i];
    m = max(m, a[i]);
  }

  if((s + k) / n >= m)
    ans = (s + k) / n;
  else{
    for(int i = 1; i <= n; i++)
      AddIntervals(a[i]);

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(auto x : v){
      if(Check(x))
        ans = max(ans, x);
    }

    for(int i = v.size() - 1; i > -1; i--){
      if(v[i + 1] == v[i] + 1)
        continue;
      ll ansx = BinarySearch(v[i] + 1, v[i + 1] - 1);
      if(ansx > 0){
        ans = max(ans, ansx);
        break;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
