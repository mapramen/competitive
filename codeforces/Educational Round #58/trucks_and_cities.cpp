#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 401

int n, m, a[N], dp[N][N][N];

int main(){
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      dp[0][i][j] = a[j] - a[i];
    }
  }

  for(int k = 1; k < n - 1; ++k){
    for(int i = 1; i < n - k; ++i){
      dp[k][i][i + k + 1] = max(a[i + k + 1] - a[i + k], dp[k - 1][i][i + k]);
      int x = i + k;
      for(int j = i + k + 2; j <= n; ++j){
        dp[k][i][j] = INT_MAX;
        for( ; x < j; ++x){
          int dpx = max(a[j] - a[x], dp[k - 1][i][x]);
          if(dpx <= dp[k][i][j]){
            dp[k][i][j] = dpx;
          }
          else{
            break;
          }
        }
        --x;
      }
    }
  }

  ll ans = 0;
  while(m--){
    int i, j, c, r;
    scanf("%d%d%d%d", &i, &j, &c, &r);
    r = min(r, j - i - 1);
    ans = max(ans, 1ll * c * dp[r][i][j]);
  }
  
  printf("%lld\n", ans);

  return 0;
}