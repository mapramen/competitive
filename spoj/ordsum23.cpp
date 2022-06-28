#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001
#define MOD 1000000007

int dp[N];

void Initialize(){
  dp[2] = 1, dp[3] = 1;
  for(int i = 4; i < N; ++i){
    dp[i] = (dp[i - 2] + dp[i - 3]) % MOD;
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