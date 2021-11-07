#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool IsPossible(ll a, ll b, ll c, ll n){
  ll z = min(c, n / 3);
  n -= 3 * z;

  z = min(b, n / 2);
  n -= 2 * z;

  return n <= a;
}

int Solve(){
  ll a, b, c;
  scanf("%lld%lld%lld", &a, &b, &c);

  ll n = a + 2ll * b + 3ll * c;
  ll m = n / 2;
  for(int k = 0; k < 3 && !IsPossible(a, b, c, m); ++m, ++k);

  return abs(n - 2 * m);
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%d\n", Solve());
  }

  return 0;
}