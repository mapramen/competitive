#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

ll GetNumberVertices(ll m){
  ll n = (1 + sqrt(1 + 8 * m)) / 2 - 1;
  while(n * (n - 1) < 2 * m)
    n++;
  return n;
}

ll BinarySearch(ll n){
  ll x = 3, y = n, z = n - 1;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    ll nx = n - GetNumberVertices(mid);
    if(nx >= mid){
      z = mid + nx;
      x = mid + 1;
    }
    else
      y = mid - 1;
  }
  return z;
}

int main(){
  ll t;
  scanf("%lld", &t);
  while(t--){
    ll n;
    scanf("%lld", &n);
    printf("%lld\n", BinarySearch(n));
  }

  return 0;
}
