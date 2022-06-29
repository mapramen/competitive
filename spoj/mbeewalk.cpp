#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 15

map<pii,ll> dp[N];

void Update(map<pii,ll>& dp, pii p, ll val){
  int x, y;
  tie(x, y) = p;

  for(int dx = -1; dx < 2; ++dx){
    for(int dy = -1; dy < 2; ++dy){
      if(dx == dy){
        continue;
      }
      dp[{x + dx, y + dy}] += val;
    }
  }
}

void Initialize(){
  dp[0][{0, 0}] = 1;

  for(int k = 0; k < N - 1; ++k){
    for(pair<pii,ll> p: dp[k]){
      Update(dp[k + 1], p.first, p.second);
    }
  }
}

ll Solve(){
  int n;
  scanf("%d", &n);
  return dp[n][{0, 0}];
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%lld\n", Solve());
  }
  
  return 0;
}