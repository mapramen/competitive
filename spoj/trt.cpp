#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  vector<vector<int>> dp(n, vector<int>(n));

  for(int i = 0; i < n; ++i){
    dp[i][i] = n * a[i];
  }

  for(int l = 2, k = n - 1; l <= n; ++l, --k){
    for(int i = 0, j = l - 1; j < n; ++i, ++j){
      dp[i][j] = max(k * a[i] + dp[i + 1][j], dp[i][j - 1] + k * a[j]);
    }
  }

  printf("%d\n", dp[0][n - 1]);
  
  return 0;
}