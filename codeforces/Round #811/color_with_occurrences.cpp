#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>

void Solve(){
  string t;
  cin >> t;

  int m;
  scanf("%d", &m);

  map<string,int> M;
  vector<int> lengths(m + 1);
  for(int i = 1; i <= m; ++i){
    string s;
    cin >> s;
    M[s] = i;
    lengths[i] = s.size();
  }

  int n = t.size();
  vector<int> dp(n + 1, n + 1), move(n + 1), parent(n + 1);

  dp[0] = 0;
  for(int i = 1; i <= n; ++i){
    pii ans = {n + 1, i};
    for(int j = i; j != 0; --j){
      string s = string(t, j - 1, i - j + 1);
      ans = min(ans, {1 + dp[j - 1], j - 1});
      
      auto it = M.find(s);
      if(it == M.end()){
        continue;
      }

      if(ans.first < dp[i]){
        dp[i] = ans.first, move[i] = it->second, parent[i] = ans.second;
      }
    }
  }

  if(dp[n] > n){
    printf("-1\n");
    return;
  }

  printf("%d\n", dp[n]);
  for(int i = n; i != 0; i = parent[i]){
    int k = move[i];
    printf("%d %d\n", k, i - lengths[k] + 1);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}