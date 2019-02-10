#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500001

ll a[N], b[N];

bool Check(int n, int r, ll k, ll m){
  for(int i = 1; i <= n; ++i)
    b[i] = a[i];

  ll s = 0;
  for(int i = 1, x = 1, y = 1; i <= n && k >= 0; ++i){
    for( ; y <= n && y - i <= r; ++y)
      s += b[y];

    for( ; i - x > r; ++x)
      s -= b[x];

    ll z = max(0ll, m - s);
    b[y - 1] += z;
    k -= z;
    s += z;
  }

  return k >= 0;
}

ll BinarySearch(int n, int r, ll k){
  ll x = 0, y = 2E18, z = 0;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Check(n, r, k, mid))
      z = mid, x = mid + 1;
    else
      y = mid - 1;
  }
  return z;
}

int main(){
  int n, r;
  ll k;

  scanf("%d%d%lld", &n, &r, &k);
  for(int i = 1; i <= n; ++i)
    scanf("%lld", &a[i]);

  printf("%lld\n", BinarySearch(n, r, k));

  return 0;
}
