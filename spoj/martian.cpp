#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 501

int Y[N][N], B[N][N], dp[N][N];

void ReadMineral(int n, int m, int A[N][N]){
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &A[i][j]);
    }
  }
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  if(n == 0){
    exit(0);
  }

  ReadMineral(n, m, Y);
  ReadMineral(n, m, B);

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    int b = 0, y = 0;
    for(int j = 1; j <= m; ++j){
      b += B[i][j];
    }

    ans = 0;
    for(int j = 0; j <= m; ++j){
      y += Y[i][j], b -= B[i][j];
      ans = max(ans, dp[i - 1][j] + y + b);
      dp[i][j] = ans;
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