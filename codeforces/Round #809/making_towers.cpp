#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int dp[2][N], c[N];

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    dp[0][i] = 0, dp[1][i] = 0, c[i] = 0;
  }

  for(int i = 1, k = 1; i <= n; ++i, k ^= 1){
    int x;
    scanf("%d", &x);
    dp[k][x] = max(dp[k][x], 1 + dp[1 ^ k][x]);
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", max(dp[0][i], dp[1][i]));
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}