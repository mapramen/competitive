#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

ll a[N];
vector<ll> C, T;

int GetCompressedValue(ll x){
  x = max(0ll, x);
  int i = lower_bound(C.begin(), C.end(), x) - C.begin();
  i -= (C[i] != x);
  return i;
}

void Update(ll i, int x){
  for(i = GetCompressedValue(i); i < T.size(); i += (i & -i))
    T[i] += x;
}

int Query(ll i){
  int ans = 0;
  for(i = GetCompressedValue(i); i > 0; i -= (i & -i))
    ans += T[i];
  return ans;
}

void PreProcess(int n){
  for(int i = 0; i <= n; ++i)
    C.PB(a[i]);

  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());
  T.resize(C.size());
}

ll Count(ll n, ll x, ll k){
  ll ans = 0;

  for(int i = 1; i <= n; ++i){
    ll p, q;

    if(k){
      q = a[i] / x - k + 1;
      p = q - 1;
      p *= x, q *= x;
    }
    else
      p = (a[i] / x) * x, q = a[i];
    ans += (Query(q) - Query(p));
    Update(a[i], 1);
  }

  return ans;
}

int main(){
  ll n, x, k, ans = 0;

  scanf("%lld%lld%lld", &n, &x, &k);

  for(int i = 1; i <= n; ++i)
    scanf("%lld", &a[i]);

  for(int i = 1; i <= n && k == 1; ++i)
    ans += (a[i] % x == 0);

  for(int i = 1; i <= n && k == 0; ++i)
    ans += (a[i] % x != 0);

  PreProcess(n);

  ans += Count(n, x, k);

  for(int i = 1; i + i <= n; ++i)
    swap(a[i], a[n - i + 1]);

  for(int i = 0; i < T.size(); ++i)
    T[i] = 0;

  ans += Count(n, x, k);

  printf("%lld\n", ans);

  return 0;
}
