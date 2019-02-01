#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 7
#define N 65

double w[N][N], p[B][N], dp[B][N];

bool IsFightPossible(int k, int i, int j){
  int x = 0;
  while(i != j){
    ++x;
    i = (i + 1) / 2;
    j = (j + 1) / 2;
  }
  return (x == k);
}

int main(){
  int b, n;
  double ans = 0;

  scanf("%d", &b);
  n = (1 << b);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      scanf("%lf", &w[i][j]);
      w[i][j] /= 100;
    }
  }

  for(int i = 1; i <= n; ++i)
    p[0][i] = 1;

  for(int k = 1; k <= b; ++k){
    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= n; ++j){
        if(IsFightPossible(k, i, j))
          p[k][i] += w[i][j] * p[k - 1][j];
      }

      p[k][i] *= p[k - 1][i];

      for(int j = 1; j <= n; ++j){
        if(IsFightPossible(k, i, j))
          dp[k][i] = max(dp[k][i], dp[k - 1][j]);
      }

      dp[k][i] += (dp[k - 1][i] + p[k][i] * (1 << (k - 1)));
    }
  }

  for(int i = 1; i <= n; ++i)
    ans = max(ans, dp[b][i]);

  printf("%.15lf\n", ans);

  return 0;
}
