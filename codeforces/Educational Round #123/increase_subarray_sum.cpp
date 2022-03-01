#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5001

int a[N], dp[N];

void Solve(){
  int n, x;
  scanf("%d%d", &n, &x);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    dp[i] = INT_MIN;
  }

  for(int i = 1; i <= n; ++i){
    int s = 0;
    for(int j = i; j <= n; ++j){
      s += a[j];
      dp[j - i + 1] = max(dp[j - i + 1], s);
    }
  }

  for(int k = 0; k <= n; ++k){
    int ans = 0;
    for(int i = 0; i <= n; ++i){
      ans = max(ans, dp[i] + min(i, k) * x);
    }
    printf("%d ", ans);
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