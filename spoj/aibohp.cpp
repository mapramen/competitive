#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 6101

int dp[N][N];

int Solve(){
  string s;
  cin >> s;

  int n = s.size();
  for(int i = 1; i <= n; ++i){
    dp[i][i] = 0;
  }

  for(int len = 2; len <= n; ++len){
    for(int i = 1, j = len; j <= n; ++i, ++j){
      dp[i][j] = s[i - 1] == s[j - 1] ? dp[i + 1][j - 1] : 1 + min(dp[i + 1][j], dp[i][j - 1]);
    }
  }
  
  return dp[1][n];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}