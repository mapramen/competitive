#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 31

char s[N];
ll dp[N];

ll Solve(){
  scanf("%s", s);

  int n = strlen(s);
  
  dp[0] = 1;
  for(int i = 1; i <= n; ++i){
    ll ans = 0;
    for(int j = i; j != 0 && s[j - 1] == s[i - 1]; --j){
      ans += dp[j - 1];
    }
    dp[i] = ans;
  }

  return dp[n];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}