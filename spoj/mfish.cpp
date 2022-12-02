#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N], dp[N];

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int m;
  scanf("%d", &m);

  vector<pii> ships;
  for(int j = 1; j <= m; ++j){
    int b, d;
    scanf("%d%d", &b, &d);
    ships.push_back({b, d});
  }
  sort(ships.begin(), ships.end());

  for(int i = 1; i <= n; ++i){
    a[i] += a[i - 1];
  }

  int last_anchor = 0;
  for(pii& ship: ships){
    int b = ship.first, d = ship.second;
    int l = max(b, last_anchor + d), r = b + d - 1;

    for(int i = last_anchor + 1; i < l; ++i){
      dp[i] = max(dp[i - 1], dp[i]);
    }

    for(int i = l; i <= r; ++i){
      dp[i] = max(dp[i], dp[i - d] + a[i] - a[i - d]);
    }
    
    for(int i = last_anchor; i < l; ++i){
      dp[i] = INT_MIN;
    }

    for(int i = l; i <= r; ++i){
      dp[i] = max(dp[i], dp[i - 1]);
    }

    last_anchor = b;
  }

  printf("%d\n", *max_element(dp, dp + n + 1));

  return 0;
}