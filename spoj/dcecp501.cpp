#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100007
#define B 3

ll s[N], dp[N];

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &s[i]);
  }

  for(int k = 1, j = n + 1; k <= 2 * B; ++k, ++j){
    s[j] = 0, dp[j] = 0;
  }

  for(int i = n; i != 0; --i){
    s[i] += s[i + 1];
  }

  for(int i = n; i != 0; --i){
    ll ans = 0;
    for(int k = 1; k <= B; ++k){
      ans = max(ans, (s[i] - s[i + k]) + dp[i + 2 * k]);
    }
    dp[i] = ans;
  }

  return dp[1];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}