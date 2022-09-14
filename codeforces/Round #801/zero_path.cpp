#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001

bitset<N> dp[N];

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int y = 0; y <= m; ++y){
    dp[y].reset();
  }

  dp[1].set(N / 2);
  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= m; ++y){
      dp[y] |= dp[y - 1];

      int z;
      scanf("%d", &z);

      if(z == 1){
        dp[y] <<= 1;
      }
      else{
        dp[y] >>= 1;
      }
    }
  }

  return dp[m].test(N / 2);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}