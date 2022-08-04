#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10000001
#define MOD 1000000007

int dp[N];

void Initialize(){
  dp[0] = 1, dp[1] = 1;
  for(int i = 4; i < N; ++i){
    int ans = (1ll * (i + 1) * dp[i - 1] - 1ll * (i - 2) * dp[i - 2] - 1ll * (i - 5) * dp[i - 3] + 1ll * (i - 3) * dp[i - 4]) % MOD;
    dp[i] = (ans + MOD) % MOD;
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return dp[n];
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}