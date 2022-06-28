#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001
#define B 10
#define MOD 1000000007

char s[N];
int dp[B];

int Solve(){
  scanf("%s", s);

  for(int k = 0; k < B; ++k){
    dp[k] = 0;
  }

  for(int n = strlen(s), i = 0; i < n; ++i){
    int k = s[i] - '0', ans = 1;
    for(int x = 0; x < k; ++x){
      ans = (ans + dp[x]) % MOD;
    }
    dp[k] = (dp[k] + ans) % MOD;
  }

  int ans = 0;
  for(int k = 0; k < B; ++k){
    ans = (ans + dp[k]) % MOD;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %d\n", k, Solve());
  }
  return 0;
}