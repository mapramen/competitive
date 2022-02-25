#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>

map<tiii,int> dp;

int DP(int t, int h, int a){
  if(h <= 0 || a <= 0){
    return 0;
  }

  auto it = dp.find({t, h, a});
  if(it != dp.end()){
    return it->second;
  }

  int ans = -1;
  if(t != 1){
    ans = max(ans, DP(1, h + 3, a + 2));
  }

  if(t != 2){
    ans = max(ans, DP(2, h - 5, a - 10));
  }

  if(t != 3){
    ans = max(ans, DP(3, h - 20, a + 5));
  }

  ++ans;
  dp[{t, h, a}] = ans;
  return ans;
}

int Solve(){
  int h, a;
  scanf("%d%d", &h, &a);
  
  int ans = 0;
  for(int t = 1; t <= 3; ++t){
    ans = max(ans, DP(t, h, a));
  }

  return ans - 1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}