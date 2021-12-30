#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

map<int,pii> dp;

int Parent(int n){
  int p = 1;
  for( ; p < n; p <<= 1);

  return p - n;
}

void InitialiseIfNeeded(int p){
  auto it = dp.find(p);
  if(it == dp.end()){
    dp[p] = {INT_MIN, -1};
  }
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    
    dp[x] = {0, i};
  }

  int maxLen = INT_MIN, maxLenI = -1, maxLenJ = -1;

  while(dp.rbegin()->first != 0){
    int x = dp.rbegin()->first;
    auto [hx, ihx] = dp.rbegin()->second;
    dp.erase(x);

    int p = Parent(x);
    InitialiseIfNeeded(p);

    auto [hp, ihp] = dp[p];

    int len = hx + 1 + hp;
    if(maxLen < len){
      maxLen = len, maxLenI = ihx, maxLenJ = ihp;
    }

    if(hp < 1 + hx){
      dp[p] = {1 + hx, ihx};
    }
  }

  printf("%d %d %d\n", maxLenI, maxLenJ, maxLen);

  return 0;
}