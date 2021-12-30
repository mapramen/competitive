#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001

int c[N][N], prefixDP[N], suffixDP[N];

int Solve(){
  int n, D;
  scanf("%d%d", &n, &D);

  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      int x;
      scanf("%d", &x);
      c[i][j] = x, c[j][i] = x;
    }
  }

  prefixDP[1] = 0;
  for(int i = 2; i <= n; ++i){
    prefixDP[i] = D + prefixDP[i - 1] + c[i - 1][i];
  }

  suffixDP[n] = 0;
  for(int i = n - 1; i > 0; --i){
    suffixDP[i] = D + suffixDP[i + 1] + c[i][i + 1];
  }

  int ans = prefixDP[n] + c[n][1] + D * (n - 1);
  for(int i = 1; i < n; ++i){
    int ansx = prefixDP[i] + suffixDP[i + 1] + D * n + c[i][n] + c[1][i + 1];
    ans = min(ans, ansx);
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