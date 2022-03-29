#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

int dp[N][N][N], inf = 1E9;

int Solve(){
  int k;
  string A, B;
  cin >> A >> B >> k;

  int n = A.size(), m = B.size();

  for(int x = 0; x <= n; ++x){
    for(int y = 0; y <= m; ++y){
      dp[x][y][0] = 0;
      for(int z = 1; z <= k; ++z){
        dp[x][y][z] = -inf;
      }
    }
  }

  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= m; ++y){
      for(int z = 1; z <= k; ++z){
        dp[x][y][z] = max(dp[x - 1][y][z], dp[x][y - 1][z]);
      }

      if(A[x - 1] != B[y - 1]){
        continue;
      }

      int c = A[x - 1];
      for(int z = 1; z <= k; ++z){
        dp[x][y][z] = max(dp[x][y][z], c + dp[x - 1][y - 1][z - 1]);
      }
    }
  }

  return dp[n][m][k] < 0 ? 0 : dp[n][m][k];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}