#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

ll M[N], S[N], P[N];

bool Check(ll t, int m, int n, int b){
  vector<ll> v;

  for(int i = 1; i <= m; ++i){
    ll x = min(max(0ll, (t - P[i]) / S[i]), 1ll * M[i]);
    if(x)
      v.PB(x);
  }

  sort(v.begin(), v.end(), greater<ll>());

  for(int i = 0; i < v.size() && i < n; ++i){
    if(v[i] >= b){
      return 1;
    }
    else
      b -= v[i];
  }

  return 0;
}

ll BinarySearch(int m, int n, int b){
  ll x = 0, y = LLONG_MAX / 2, z = y;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Check(mid, m, n, b))
      z = mid, y = mid - 1;
    else
      x = mid + 1;
  }
  return z;
}

ll Solve(){
  int n, m, b;

  scanf("%d%d%d", &n, &b, &m);

  for(int i = 1; i <= m; ++i)
    scanf("%lld%lld%lld", &M[i], &S[i], &P[i]);

  return BinarySearch(m, n, b);
}

int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %lld\n", k, Solve());
  }

  return 0;
}
