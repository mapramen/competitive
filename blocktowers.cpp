#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

bool Check(ll k, ll n, ll m){
  ll n1 = k / 2, n2 = k / 3, n3 = k / 6;
  n1 -= n3, n2 -= n3;
  n -= min(n, n1), m -= min(m, n2);
  return (n + m <= n3);
}

ll BinarySearch(ll n, ll m){
  ll x = 0, y = LLONG_MAX, z = y;

  while(x <= y){
    ll mid = x + (y - x) / 2;

    if(Check(mid, n, m))
      z = mid, y = mid - 1;
    else
      x = mid + 1;
  }

  return z;
}

int main(){
  ll n, m;

  cin >> n >> m;
  cout << BinarySearch(n, m) << '\n';
  
  return 0;
}
