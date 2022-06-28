#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

int dp[N];

void Initialize(){
  for(int i = 1; i < N; ++i){
    dp[i] = i;
  }

  for(int x = 1; x * x < N; ++x){
    for(int i = x * x, j = 0; i < N; ++i, ++j){
      dp[i] = min(dp[i], 1 + dp[j]);
    }
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