#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 20
#define M (1 << N)

int a[N][N];
ll dp[M];

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  int m = (1 << n);
  dp[0] = 1;

  for(int mask = 1; mask < m; ++mask){
    int i = __builtin_popcount(mask) - 1;

    ll ans = 0;
    for(int j = 0; j < n; ++j){
      if(a[i][j] == 0 || (mask & (1 << j)) == 0){
        continue;
      }
      ans += dp[(mask ^ (1 << j))];
    }

    dp[mask] = ans;
  }

  return dp[m - 1];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}