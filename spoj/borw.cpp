#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 205

int a[N], dp[N][N][N];

int CoordinateCompress(int n){
  vector<int> C {INT_MIN, INT_MAX};
  for(int i = 1; i <= n; ++i){
    C.push_back(a[i]);
  }
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  for(int i = 1; i <= n; ++i){
    a[i] = lower_bound(C.begin(), C.end(), a[i]) - C.begin();
  }

  return C.size() - 1;
}

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == -1){
    exit(0);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int m = CoordinateCompress(n);

  for(int x = 0; x <= m; ++x){
    for(int y = 0; y <= m; ++y){
      dp[0][x][y] = 0;
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int x = 0; x <= m; ++x){
      for(int y = 0; y <= m; ++y){
        dp[i][x][y] = 1 + dp[i - 1][x][y];
      }
    }

    for(int nx = a[i], x = a[i] - 1; x != -1; --x){
      for(int y = 0; y <= m; ++y){
        dp[i][nx][y] = min(dp[i][nx][y], dp[i - 1][x][y]);
      }
    }

    for(int x = 0; x <= m; ++x){
      for(int ny = a[i], y = a[i] + 1; y <= m; ++y){
        dp[i][x][ny] = min(dp[i][x][ny], dp[i - 1][x][y]);
      }
    }
  }

  int ans = n;
  for(int x = 0; x <= m; ++x){
    for(int y = 0; y <= m; ++y){
      ans = min(ans, dp[n][x][y]);
    }
  }

  return ans;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}