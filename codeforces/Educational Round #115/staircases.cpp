#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1002

bool isFree[N][N];
pll dp[N][N];

ll Calculate(int i, int j){
  dp[i][j] = {0ll, 0ll};

  if(!isFree[i][j]){
    return 0ll;
  }

  ll x = 1 + dp[i][j + 1].second, y = 1 + dp[i + 1][j].first;
  dp[i][j] = {x, y};

  return x + y - 1;
}

ll GetChainCount(int i, int j){
  ll ans = 0;
  
  while(i > 0 && j > 0){
    ans += Calculate(i, j);

    if(i != 0){
      ans += Calculate(i - 1, j);
    }

    if(j != 0){
      ans += Calculate(i, j - 1);
    }

    --i, --j;
  }

  return ans;
}

int main(){
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      isFree[i][j] = true;
    }
  }

  ll ans = 0;
  for(int i = n; i != 0; --i){
    for(int j = m; j != 0; --j){
      ans += Calculate(i, j);
    }
  }

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);

    ans -= GetChainCount(i, j);
    isFree[i][j] = !isFree[i][j];
    ans += GetChainCount(i, j);

    printf("%lld\n", ans);
  }

  return 0;
}