#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define B 10
#define M (1 << B)
#define MOD 1000000007

vector<vector<int>> adj(M);
int dp[N][M], s[N];

bool IsValid(int mask, int d){
  if(d == 0){
    return mask != 0;
  }

  for(int i = 2; i < B; ++i){
    if((mask & (1 << i)) != 0 && d % i == 0){
      return true;
    }
  }
  
  return false;
}

void Initialize(){
  for(int d = 1; d < B; ++d){
    adj[0].push_back((1 << d));
  }

  for(int mask = 1; mask < M; ++mask){
    for(int d = 0; d < B; ++d){
      if(IsValid(mask, d)){
        adj[mask].push_back(mask | (1 << d));
      }
    }
  }

  dp[0][0] = 1;
  for(int i = 1; i < N; ++i){
    for(int mask = 0; mask < M; ++mask){
      for(int nmask: adj[mask]){
        dp[i][nmask] = (dp[i][nmask] + dp[i - 1][mask]) % MOD; 
      }
    }

    for(int mask = 0; mask < M; ++mask){
      s[i] = (s[i] + dp[i][mask]) % MOD;
    }
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return s[n];
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