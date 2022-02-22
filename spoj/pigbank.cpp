#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define INF 1E9

int Solve(){
  int e, f;
  scanf("%d%d", &e, &f);

  int n, m = f - e;
  scanf("%d", &n);

  vector<int> dp(m + 1, INF);

  dp[0] = 0;
  while(n--){
    int cost, weight;
    scanf("%d%d", &cost, &weight);
    for(int i = weight, j = 0; i <= m; ++i, ++j){
      dp[i] = min(dp[i], dp[j] + cost);
    }
  }

  return dp[m] == INF ? -1 : dp[m];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int ans = Solve();

    if(ans != -1){
      printf("The minimum amount of money in the piggy-bank is %d.\n", ans);
    }
    else{
      printf("This is impossible.\n");
    }
  }
  return 0;
}