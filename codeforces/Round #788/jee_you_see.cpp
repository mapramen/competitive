#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define B 60
#define MOD 1000000007

ll max_sum[B], INF = 2E18;
int c[N], cnt[B];

ll Query(int n, ll z, ll k, ll x){
  if(k == -1){
    return 1;
  }

  if(max_sum[k] <= x){
    return cnt[k];
  }

  ll p = (1ll << k);
  int i = (z & p) != 0;
  ll sum = i * p;

  int ans = 0;
  for( ; i <= n && sum <= x; i += 2, sum += 2 * p){
    ans = (ans + 1ll * c[i] * Query(n, z, k - 1, x - sum)) % MOD;
  }

  return ans;
}

int main(){
  int n;
  ll l, r, z;
  scanf("%d%lld%lld%lld", &n, &l, &r, &z);

  for(int i = 0; i <= n; ++i){
    c[0] = 1;
    for(int j = i; j != 0; --j){
      c[j] = (c[j - 1] + c[j]) % MOD;
    }
  }

  for(int k = 0; k < B; ++k){
    ll p = (1ll << k);
    int i = (z & p) != 0;
    ll sum = i * p;

    for( ; i <= n; i += 2, sum = min(INF, sum + 2 * p)){
      max_sum[k] = sum;
      cnt[k] = (cnt[k] + c[i]) % MOD;
    }
  }

  for(int k = 1; k < B; ++k){
    max_sum[k] = min(INF, max_sum[k] + max_sum[k - 1]);
    cnt[k] = (1ll * cnt[k] * cnt[k - 1]) % MOD;
  }

  int ans = (MOD + Query(n, z, B - 1, r) - Query(n, z, B - 1, l - 1)) % MOD;

  printf("%d\n", ans);

  return 0;
}