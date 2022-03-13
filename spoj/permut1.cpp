#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 12
#define M (1 << N)
#define K 99

int dp[M][K];

void Initialise(){
  dp[0][0] = 1;

  for(int mask = 0; mask < M; ++mask){
    for(int i = 0, val = 0; i < N; ++i){
      if((mask & (1 << i)) != 0){
        continue;
      }

      int nmask = mask ^ (1 << i);
      for(int k = 0, nk = val; nk < K; ++k, ++nk){
        dp[nmask][nk] += dp[mask][k];
      }

      ++val;
    }
  }
}

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);
  return dp[(1 << n) - 1][k];
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}