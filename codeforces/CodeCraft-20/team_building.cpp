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
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 200001
#define M 7

vector< vector<int> > moves((1 << M));
int a[N], s[N][M];
ll dp[2][(1 << M)];

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 0; j < m; ++j){
      scanf("%d", &s[i][j]);
    }
  }

  vector< pii > v;
  for(int i = 1; i <= n; ++i){
    v.push_back(make_pair(a[i], i));
  }
  sort(v.begin(), v.end(), greater< pii >());

  for(int i = 0; i < 2; ++i){
    for(int mask = 0; mask < (1 << m); ++mask){
      dp[i][mask] = LLONG_MIN;
    }
  }

  for(int mask = 0; mask < (1 << m); ++mask){
    for(int j = 0; j < m; ++j){
      if((mask & (1 << j)) == 0){
        moves[mask].push_back(j);
      }
    }
  }

  int cur = 0;
  dp[cur][0] = 0;
  for(int i = 1; i <= n; ++i, cur = 1 - cur){
    const int nxt = 1 - cur, x = v[i - 1].second;

    for(int mask = 0; mask < (1 << m); ++mask){
      for(int j : moves[mask]){
        int nmask = mask | (1 << j);
        dp[nxt][nmask] = max(dp[nxt][nmask], dp[cur][mask] + s[x][j]);
      }

      dp[nxt][mask] = max(dp[nxt][mask], dp[cur][mask] + (max(0, i - __builtin_popcount(mask)) <= k ? a[x] : 0));
    }
  }

  printf("%lld\n", dp[cur][(1 << m) - 1]);

  return 0;
}