#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5002

int a[N], c[N], dp[N];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 0; i <= n; ++i){
    c[i] = 0;
  }

  dp[0] = 0;
  for(int i = 1; i <= n + 1; ++i){
    int mx = 0, mxi = -1, ans = -n;
    for(int j = i - 1; j != -1; --j){
      if(i > n){
        a[i] = a[j];
      }

      if(j == 0){
        a[j] = a[i];
      }

      int k = i - j - 1;
      if(a[j] == a[i] && k % 2 == 0 && 2 * mx <= k){
        ans = max(ans, 1 + dp[j]);
      }

      if(++c[a[j]] > mx){
        mx = c[a[j]], mxi = a[j];
      }
    }

    for(int x = 0; x <= n; ++x){
      c[x] = 0;
    }

    dp[i] = ans;
  }

  return dp[n + 1] - 1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}