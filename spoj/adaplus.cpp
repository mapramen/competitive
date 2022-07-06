#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001

char s[N][N];
int dp[N][N];

int Update(int i, int j, int x){
  x = s[i - 1][j - 1] == '#' ? 1 + x : 0;
  dp[i][j] = min(dp[i][j], x);
  return x;
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      dp[i][j] = INT_MAX;
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1, x = 0; j <= n; ++j){
      x = Update(i, j, x);
    }

    for(int j = n, x = 0; j != 0; --j){
      x = Update(i, j, x);
    }
  }

  for(int j = 1; j <= n; ++j){
    for(int i = 1, x = 0; i <= n; ++i){
      x = Update(i, j, x);
    }

    for(int i = n, x = 0; i != 0; --i){
      x = Update(i, j, x);
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      ans = max(ans, dp[i][j]);
    }
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