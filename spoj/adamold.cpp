#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5001
#define B 30

int a[N], c[B];
ll cost[N][N], dp[N][N];

void DivideAndConquer(int k, int i, int j, int l, int r){
  if(i > j){
    return;
  }

  if(l == r){
    for( ; i <= j; ++i){
      dp[k][i] = dp[k - 1][l - 1] + cost[l][i];
    }
    return;
  }

  int m = (i + j) / 2, mid = l;
  ll ans = LLONG_MAX;
  for(int x = l; x <= min(m, r); ++x){
    ll ansx = dp[k - 1][x - 1] + cost[x][m];
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
  ++m;

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    for(int k = 0; k < B; ++k){
      c[k] = 0;
    }

    for(int j = i, len = 1; j <= n; ++j, ++len){
      for(int k = 0; k < B; ++k){
        c[k] += ((a[j] & (1 << k)) != 0);
      }

      ll ans = 0;
      for(int k = 0; k < B; ++k){
        ans += 1ll * c[k] * (len - c[k]) * (1 << k);
      }

      cost[i][j] = ans;
    }
  }

  for(int i = 1; i <= n; ++i){
    dp[0][i] = 1E18;
  }

  for(int k = 1; k <= m; ++k){
    DivideAndConquer(k, 1, n, 1, n);
  }

  printf("%lld\n", dp[m][n]);

  return 0;
}