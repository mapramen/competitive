#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 2
#define N 10001

int a[B][N], dp[B][N];

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int k = 0; k < B; ++k){
    for(int i = 1; i <= n; ++i){
      scanf("%d", &a[k][i]);
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int k = 0; k < B; ++k){
      dp[k][i] = dp[k][i - 1] + a[k][i];
    }

    for(int k = 0; k < B; ++k){
      int ansx = INT_MAX, s = 0;
      for(int kx = 0; kx < B; ++kx){
        ansx = min(ansx, dp[kx][i] - a[kx][i]);
        s += a[kx][i];
      }
      dp[k][i] = min(dp[k][i], ansx + s);
    }
  }

  int station = n;
  while(true){
    bool exceeds = true;
    for(int k = 0; k < B && exceeds; ++k){
      exceeds = dp[k][station] > m;
    }
    if(!exceeds){
      break;
    }
    --station;
  }

  int min_count = INT_MAX;
  for(int k = 0; k < B; ++k){
    min_count = min(min_count, dp[k][station]);
  }

  printf("%d %d\n", station, min_count);

  return 0;
}