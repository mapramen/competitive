#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 50000

bitset<N + 1 + N> dp;

int Solve(){
  int n;
  scanf("%d", &n);

  dp.reset();
  dp[N] = true;

  while(n--){
    int x, y;
    scanf("%d%d", &x, &y);
    
    int i = abs(x - y);
    dp = (dp << i) | (dp >> i);
  }

  int ans = N;
  for(int i = 0; i < 1 + 2 * N; ++i){
    if(!dp[i]){
      continue;
    }
    ans = min(ans, abs(i - N));
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}