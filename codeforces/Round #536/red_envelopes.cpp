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

#define pii pair< int, int>
#define pll pair< ll, ll>
#define ppiii pair< pii, int >
#define N 100001
#define M 201

vector< vector<int> > v(N);
int t[N], d[N], w[N];
ll dp[M][N];
const ll inf = 1E18;

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  for(int i = 1, s; i <= k; ++i){
    scanf("%d%d%d%d", &s, &t[i], &d[i], &w[i]);
    v[s].push_back(i);
  }

  for(int i = 0; i <= m; ++i){
    for(int j = 0; j <= n; ++j){
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 0;

  priority_queue< ppiii > Q;
  for(int j = 1; j <= n; ++j){
    while(!Q.empty() && Q.top().second < j){
      Q.pop();
    }

    for(int x : v[j]){
      Q.push(make_pair(make_pair(w[x], d[x]), t[x]));
    }
    Q.push(make_pair(make_pair(0, j), j));

    for(int i = 1; i <= m; ++i){
      dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
    }

    int jx, x;
    tie(x, jx) = Q.top().first;
    for(int i = 0; i <= m; ++i){
      dp[i][jx] = min(dp[i][jx], dp[i][j - 1] + x);
    }
  }

  ll ans = inf;
  for(int i = 0; i <= m; ++i){
    ans = min(ans, dp[i][n]);
  }

  printf("%lld\n", ans);

  return 0;
}