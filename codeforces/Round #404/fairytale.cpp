#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

bool Check(ll n, ll m, ll mid){
  return (n - m - mid * (mid + 1) / 2) <= 0;
}

ll BinarySearch(ll n, ll m){
  ll x = 0, y = 2E9, z;

  while(x <= y){
    ll mid = x + (y - x) / 2;

    if(Check(n, m, mid)){
      z = mid;
      y = mid - 1;
    }
    else
      x = mid + 1;
  }

  return z;
}

int main(){
  ll n, m, ans;

  cin >> n >> m;

  if(m >= n)
    ans = n;
  else
    ans = m + BinarySearch(n, m);

  cout << ans << '\n';

  return 0;
}
