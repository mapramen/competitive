#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 30

int a[N], dp[N][N];

int RelativeToAbsolute(int n){
  int ans = dp[0][n - 1];
  for(int i = 0; i < n; ++i){
    ans += a[i];
  }
  return ans / 2;
}

int CalculateDumb(int n){
  for(int i = 0; i < n; ++i){
    dp[i][i] = a[i];
  }

  for(int k = 2; k <= n; ++k){
    for(int i = 0, j = k - 1; j < n; ++i, ++j){
      if(k % 2 == 0){
        dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
      }
      else{
        dp[i][j] = min(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
      }
    }
  }

  return RelativeToAbsolute(n);
}

int CalculateSmart(int n){
  for(int i = 0; i < n; ++i){
    dp[i][i] = a[i];
  }

  for(int k = 2; k <= n; ++k){
    for(int i = 0, j = k - 1; j < n; ++i, ++j){
      dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
    }
  }

  return RelativeToAbsolute(n);
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  printf("%d %d\n", CalculateDumb(n), CalculateSmart(n));
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}