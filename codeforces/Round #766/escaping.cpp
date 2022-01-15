#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define t4i tuple<int,int,int,int>

ll inf = 1E18;
vector<int> X;
vector<vector<t4i>> ladders;
vector<map<int,ll>> dp;

void Reset(int n){
  X.clear(), ladders.clear(), dp.clear();
  X.resize(n), ladders.resize(n), dp.resize(n);
}

string Solve(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  Reset(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &X[i]);
  }

  while(k--){
    int a, b, c, d, h;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &h);
    --a, --b, --c, --d;
    
    ladders[a].push_back({b, c, d, h});

    dp[a][b] = inf;
    dp[c][d] = inf;
  }

  dp[0][0] = 0;
  dp[n - 1][m - 1] = inf;

  for(int x = 0; x < n; ++x){
    int C = X[x];
    map<int,ll>& dpx = dp[x];
    
    ll ans = inf;
    int py = INT_MIN;
    for(auto yt = dpx.begin(); yt != dpx.end(); ++yt){
      int cy = yt->first;
      ans = min(yt->second, 1ll * C * (cy - py) + ans);
      yt->second = ans;
      py = cy;
    }
    
    ans = inf;
    py = INT_MAX;
    for(auto yt = dpx.rbegin(); yt != dpx.rend(); ++yt){
      int cy = yt->first;
      ans = min(yt->second, 1ll * C * (py - cy) + ans);
      yt->second = ans;
      py = cy;
    }

    for(auto [y, c, d, h]: ladders[x]){
      auto nt = dp[c].find(d);
      nt->second = min(nt->second, dpx[y] - h);
    }
  }

  ll ans = dp[n - 1][m - 1];

  return (ans >= inf / 2) ? "NO ESCAPE" : to_string(ans);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}