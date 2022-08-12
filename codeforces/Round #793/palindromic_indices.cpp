#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string s;
map<pii,bool> dp;

void Reset(){
  dp.clear();
}

bool DP(int i, int j){
  if(j < i){
    return true;
  }

  auto it = dp.find({i, j});
  if(it != dp.end()){
    return it->second;
  }

  bool ans = (s[i] == s[j]) && DP(i + 1, j - 1);

  dp[{i, j}] = ans;
  return ans;
}

int Solve(){
  int n;
  scanf("%d", &n);

  cin >> s;

  Reset();

  int ans = 0;
  for(int i = 0; i < n; ++i){
    int j = n - 1 - i;
    ans += (i < j ? DP(i + 1, j) : DP(j, i - 1));
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}