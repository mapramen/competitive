#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

bool Check(ll m, ll s){
  ll k = 0;
  for(ll x = m; x > 0; x /= 10)
    k += (x % 10);
  return (m - k >= s);
}

ll BinarySearch(ll n, ll s){
  ll x = 1, y = n + 1, z = n + 1;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Check(mid, s))
      z = mid, y = mid - 1;
    else
      x = mid + 1;
  }
  return (n - z + 1);
}

int main(){
  ll n, s;

  cin >> n >> s;
  cout << BinarySearch(n, s) << '\n';

  return 0;
}
