#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define MOD 998244353 

int s[N], dp[N], ans[N];

int main(){
  int n, k;
  scanf("%d%d", &n, &k);

  dp[0] = 1;
  for(int m = k; m <= n; ++k, m += k){
    for(int r = 0; r < k; ++r){
      s[r] = 0;
    }

    for(int i = 0; i <= n; ++i){
      int r = i % k, ansx = s[r];
      
      s[r] = (s[r] + dp[i]) % MOD;
      dp[i] = ansx;
      ans[i] = (ans[i] + ansx) % MOD;
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}