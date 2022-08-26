#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 25

map<int,vector<int>> dp;

vector<int> DP(int n){
  if(n == 0){
    return {1, 0};
  }
  
  if(n < 10){
    return {n};
  }

  auto it = dp.find(n);
  if(it != dp.end()){
    return it->second;
  }

  vector<int> ans(N);
  for(int d = 2; d < 10; ++d){
    if(n % d != 0){
      continue;
    }

    vector<int> v{d};
    for(int x: DP(n / d)){
      v.push_back(x);
    }

    if(v.size() < ans.size() || (v.size() == ans.size() && v < ans)){
      ans = v;
    }
  }

  dp[n] = ans;
  return ans;
}

ll Solve(){
  int n;
  scanf("%d", &n);

  vector<int> v = DP(n);
  if(v.size() == N){
    return -1;
  }

  ll ans = 0;
  for(int d: v){
    ans = 10 * ans + d;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}