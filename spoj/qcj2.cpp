#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101
#define MOD 761238923

int dp[N];

void Initialize(){
  dp[0] = 1;
  for(int i = 1; i < N; ++i){
    int ans = 0;
    for(int j = 0; j < i; ++j){
      ans = (ans + 1ll * dp[j] * dp[i - j - 1]) % MOD;
    }
    dp[i] = ans;
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  
  if(n == 0){
    exit(0);
  }

  return dp[n];
}

int main(){
  Initialize();
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}