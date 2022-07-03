#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 251

int a[N];
map<tiii,int> dp[N];

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  dp[0][{0, m, 0}] = 0;
  for(int i = 1; i <= n; ++i){
    for(auto [t, val]: dp[i - 1]){
      auto [x, y, z] = t;

      for(int ny = min(m - x, y); ny != -1; --ny){
        int nx = x + ny, nz = z + ny - a[i];
        int ans = val + abs(nz);
      
        tiii nt = {nx, ny, nz};
        auto it = dp[i].find(nt);
        if(it == dp[i].end()){
          dp[i][nt] = ans;
        }
        else{
          it->second = min(it->second, ans);
        }
      }
    }
  }

  int ans = INT_MAX;
  for(auto [t, val]: dp[n]){
    auto [x, y, z] = t;
    if(z == 0){
      ans = min(ans, val);
    }
  }

  printf("%d\n", ans);
  
  return 0;
}