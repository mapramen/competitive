#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5001

int a[N], s[N][N], dp[N][N];

void PreProcess(int n){
  for(int i = 1; i <= n; ++i){
    for(int j = i; j <= n; ++j){
      s[i][j] = a[i] > a[j];
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }
  }
}

int Cost(int i, int j){
  return s[j][j] + s[i - 1][i - 1] - s[i - 1][j] - s[j][i - 1];
}

void DivideAndConquer(int k, int i, int j, int l, int r){
  if(i > j){
    return;
  }

  if(l == r){
    for( ; i <= j; ++i){
      dp[k][i] = dp[k - 1][l - 1] + Cost(l, i);
    }
    return;
  }

  int m = (i + j) / 2, mid = l, ans = INT_MAX;
  for(int x = l; x <= min(m, r); ++x){
    int ansx = dp[k - 1][x - 1] + Cost(x, m);
    if(ansx < ans){
      ans = ansx, mid = x;
    }
  }

  dp[k][m] = ans;
  DivideAndConquer(k, i, m - 1, l, mid);
  DivideAndConquer(k, m + 1, j, mid, r);
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  PreProcess(n);

  for(int k = 0; k <= m; ++k){
    for(int i = 0; i <= n; ++i){
      dp[k][i] = N * N;
    }
  }

  dp[0][0] = 0;
  for(int k = 1; k <= m; ++k){
    DivideAndConquer(k, 1, n, 1, n);
  }

  printf("%d\n", dp[m][n]);

  return 0;
}