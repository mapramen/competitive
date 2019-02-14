#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define MOD 998244353

ll p2[N];

int main(){
  int n;

  scanf("%d", &n);

  p2[0] = 1;
  for(int i = 1; i < n; ++i){
    p2[i] = (2 * p2[i - 1]) % MOD;
  }

  ll ans = 0;
  for(ll i = 1, a = 0, b = 0, ansx = 0; i <= n; ++i, a = b){
    scanf("%lld", &b);
    ansx = (ansx + p2[n - i] * (MOD + b - a)) % MOD;
    ans = (ans + ansx) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}
