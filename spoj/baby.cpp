#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 16
#define M (1 << N)

int a[N], b[N], dp[M];

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  for(int j = 0; j < n; ++j){
    scanf("%d", &b[j]);
  }

  for(int mask = 1, inf = n * n * n; mask < (1 << n); ++mask){
    dp[mask] = inf;
  }

  for(int mask = 0; mask < (1 << n); ++mask){
    int i = __builtin_popcount(mask);

    for(int tmask = ((1 << n) - 1) ^ mask; tmask != 0; ){
      int j = __builtin_ctz(tmask);
      tmask ^= (1 << j);

      int nmask = mask | (1 << j);
      dp[nmask] = min(dp[nmask], dp[mask] + abs(i - j) + abs(a[i] - b[j]));
    }
  }

  return dp[(1 << n) - 1];
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}