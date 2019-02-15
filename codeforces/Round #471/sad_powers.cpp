#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 60

ll c[B];

bool CheckPower(ll a, ll b, ll n){
  while(b-- && n != 0)
    n /= a;
  return n > 0;
}

ll Solve(ll n){
  if(n == 0)
    return 0ll;

  for(ll p = 2; p < 60; ++p){
    ll a = max(1ll, (ll)(floor(pow(n, 1.0 / p))) - 1);
    while(CheckPower(a, p, n))
      ++a;
    --a;
    c[p] = a - 1;
  }

  for(int i = B - 1; i > 1; --i)
    for(int j = i + i; j < B; j += i)
      c[i] -= c[j];

  ll ans = 1;
  for(int i = 2; i < B; ++i)
    ans += c[i];

  return ans;
}

int main(){
  int q;

  scanf("%d", &q);
  while(q--){
    ll l, r;
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", Solve(r) - Solve(l - 1));
  }

  return 0;
}
