#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define M 10001

int a[N], c[N];
ll dp[M];

int main(){
  int n, w, b, x;

  scanf("%d%d%d%d", &n, &w, &b, &x);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &c[i]);

  dp[0] = w;
  for(int i = 1; i < M; ++i)
    dp[i] = LLONG_MIN;

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= a[i]; ++j){
      for(int k = M - 1; k > 0; --k){
        if(dp[k - 1] >= c[i])
          dp[k] = max(dp[k], dp[k - 1] - c[i]);
      }
    }

    for(int j = 0; j < M; ++j)
      dp[j] = min(w + 1ll * j * b, dp[j] + x);
  }

  int ans = 0;
  for(int i = 0; i < M; ++i)
    if(dp[i] >= 0)
      ans = i;

  cout << ans << '\n';

  return 0;
}
