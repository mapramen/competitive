#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define B 10

char s[N];
int dp[(1 << B)];

int Solve(){
  int n, d;
  scanf("%d%d", &n, &d);

  for(int mask = 0; mask < (1 << B); ++mask){
    dp[mask] = B + 1;
  }

  dp[0] = 0;
  while(n--){
    scanf("%s", s);

    int smask = 0;
    for(int i = 0; i < d; ++i){
      smask |= (1 << (s[i] - '0'));
    }

    for(int mask = 0; mask < (1 << B); ++mask){
      int nmask = mask | smask;
      dp[nmask] = min(dp[nmask], dp[mask] + 1);
    }
  }

  return dp[(1 << B) - 1] > B ? -1 : dp[(1 << B) - 1];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}