#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  string s;
  cin >> s;

  if(s.front() == '-'){
    exit(0);
  }

  int n = s.size(), m = n / 2;
  vector<int> dp(m + 1, n), t(m + 1);

  dp[0] = 0;
  for(int i = 1; i <= n; ++i){
    int cost_open = s[i - 1] == '}', cost_close = s[i - 1] == '{';

    fill(t.begin(), t.end(), n);

    for(int j = 1; j <= m; ++j){
      t[j] = min(t[j], dp[j - 1] + cost_open);
    }

    for(int j = 0; j < m; ++j){
      t[j] = min(t[j], dp[j + 1] + cost_close);
    }

    swap(dp, t);
  }

  return dp[0];
}

int main(){
  int k = 1;
  while(true){
    printf("%d. %d\n", k, Solve());
    ++k;
  }
  return 0;
}