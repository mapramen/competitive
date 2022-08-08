#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 50001
#define B 10
#define M (1 << B)
#define MOD 998244353 

int adj_mask[B], clique_cnt[B + 1], dp[N];
bool clique[M];

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj_mask[i] |= (1 << j);
    adj_mask[j] |= (1 << i);
  }

  clique[0] = true;
  for(int mask = 1; mask < M; ++mask){
    int k = __builtin_ctz(mask);
    int nmask = mask ^ (1 << k);
    clique[mask] = clique[nmask] && ((adj_mask[k] & nmask) == nmask);
  }

  for(int mask = 0; mask < M; ++mask){
    if(clique[mask]){
      ++clique_cnt[__builtin_popcount(mask)];
    }
  }

  dp[0] = 1;
  for(int i = 1; i <= n; ++i){
    int ans = 0;
    for(int j = 1; j <= B && j <= i; ++j){
      ans = (ans + (j % 2 == 1 ? 1 : -1) * 1ll * dp[i - j] * clique_cnt[j]) % MOD;
    }
    dp[i] = (MOD + ans) % MOD;
  }

  printf("%d\n", dp[n]);
  
  return 0;
}