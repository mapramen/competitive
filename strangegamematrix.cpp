#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101
#define M 10001

int a[N][N], dp[N][M];

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      scanf("%d", &a[i][j]);

  for(int j = 1; j <= m; ++j){
    queue<int> Q;
    for(int i = 1; i <= n; ++i){
      if(a[i][j])
        Q.push(i);
      a[i][j] += a[i - 1][j];
    }

    for(int y = 0; y < M; ++y)
      dp[j][y] = dp[j - 1][y];

    int x = 0;
    while(!Q.empty()){
      int i = Q.front();
      Q.pop();

      int ix = min(n, i + k - 1);
      int c = a[ix][j] - a[i - 1][j];

      for(int y = x; y < M; ++y)
        dp[j][y] = max(dp[j][y], c + dp[j - 1][y - x]);
        
      ++x;
    }
  }

  int ans_y = 0;
  for(int y = 0; y < M; ++y){
    if(dp[m][y] > dp[m][ans_y])
      ans_y = y;
  }

  printf("%d %d\n", dp[m][ans_y], ans_y);

  return 0;
}
