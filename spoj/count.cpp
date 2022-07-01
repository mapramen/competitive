#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5001
#define MOD 1988

int s[N], dp[N][N];

void Initialize(){
  dp[0][0] = 1;

  for(int k = 1; k < N; ++k){
    for(int r = 0; r < k; ++r){
      s[r] = 0;
    }

    for(int i = 0; i < N; ++i){
      int r = i % k;
      s[r] = (s[r] + dp[k - 1][i]) % MOD;
      dp[k][i] = s[r];
    }
  }

  for(int k = N - 1; k != 0; --k){
    for(int i = 1; i < N; ++i){
      dp[k][i] = (dp[k][i] + MOD - dp[k - 1][i]) % MOD;
    }
  }
}

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  if(n == 0 && k == 0){
    exit(0);
  }

  return dp[k][n];
}

int main(){
  Initialize();
  
  while(true){
    printf("%d\n", Solve());
  }
  
  return 0;
}