#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

int a[N], dp[N][N + 1][N + 1];

void PreProcess(int n){
  vector<int> C;
  for(int i = 1; i <= n; ++i){
    C.push_back(a[i]);
  }
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  for(int i = 1; i <= n; ++i){
    a[i] = lower_bound(C.begin(), C.end(), a[i]) - C.begin() + 1;
  }
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  PreProcess(n);

  for(int x = 0; x <= N; ++x){
    for(int y = 0; y <= N; ++y){
      dp[0][x][y] = INT_MIN;
    }
  }

  dp[0][0][N] = 0;
  for(int i = 1; i <= n; ++i){
    for(int x = 0; x <= N; ++x){
      for(int y = 0; y <= N; ++y){
        dp[i][x][y] = dp[i - 1][x][y];
      }
    }

    for(int y = 0; y <= N; ++y){
      int ans = INT_MIN;
      for(int x = a[i] - 1; x >= 0; --x){
        ans = max(ans, dp[i - 1][x][y]);
      }
      dp[i][a[i]][y] = max(1 + ans, dp[i][a[i]][y]);
    }

    for(int x = 0; x <= N; ++x){
      int ans = INT_MIN;
      for(int y = a[i] + 1; y <= N; ++y){
        ans = max(ans, dp[i - 1][x][y]);
      }
      dp[i][x][a[i]] = max(1 + ans, dp[i][x][a[i]]);
    }
  }

  int ans = 0;
  for(int x = 0; x <= N; ++x){
    for(int y = 0; y <= N; ++y){
      ans = max(ans, dp[n][x][y]);
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