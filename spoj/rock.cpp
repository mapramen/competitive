#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 201

char s[N];
int dp[N];

int Solve(){
  int n;
  scanf("%d%s", &n, s);

  for(int i = 1; i <= n; ++i){
    int x = 0, ans = dp[i - 1];
    for(int j = i; j > 0; --j){
      x += (s[j - 1] == '1' ? 1 : -1);
      if(x > 0){
        ans = max(ans, i - j + 1 + dp[j - 1]);
      }
    }
    dp[i] = ans;
  }

  return dp[n];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}