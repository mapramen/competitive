#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  if(n == 0 && m == 0){
    exit(0);
  }

  vector<int> dp(n + 1);
  while(m--){
    int cost, value;
    scanf("%d%d", &cost, &value);

    for(int i = n, j = n - cost; j >= 0; --j, --i){
      dp[i] = max(dp[i], dp[j] + value);
    }
  }

  int maxValue = 0, minCost = 0;
  for(int i = 0; i <= n; ++i){
    if(dp[i] > maxValue){
      maxValue = dp[i], minCost = i;
    }
  }

  printf("%d %d\n", minCost, maxValue);
}

int main(){
  while(true){
    Solve();
  }
  return 0;
}