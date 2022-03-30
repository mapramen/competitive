#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M 1001

int dp[M];

int Solve(){
  int m, n;
  scanf("%d%d", &m, &n);

  for(int i = 0; i <= m; ++i){
    dp[i] = 0;
  }

  while(n--){
    int x, c;
    scanf("%d%d", &x, &c);

    for(int i = m, j = m - x; j > -1; --i, --j){
      dp[i] = max(dp[i], dp[j] + c);
    }
  }

  return *max_element(dp, dp + m + 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("Hey stupid robber, you can get %d.\n", Solve());
  }
  return 0;
}