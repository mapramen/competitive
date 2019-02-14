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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500001
#define B 20

vector< vector<int> > adj(N);
int a[N], ancestors[B][N], dp[B][N];
const int inf = 2E9;

ll DFS(int i, int p = 0){
  ancestors[0][i] = p;
  dp[0][i] = (p > 0) ? a[p] : inf;

  ll ans = (p > 0) ? a[i] + a[p] : 0;
  for(int k = 1; k < B; ++k){
    int j = ancestors[k - 1][i];
    dp[k][i] = min(dp[k - 1][i], dp[k - 1][j]);
    ancestors[k][i] = ancestors[k - 1][j];
    if(dp[k][i] < a[i]){
      ans = min(ans, a[i] + 1ll * (1 + k) * dp[k][i]);
    }
  }

  for(auto j : adj[i]){
    if(j == p){
      continue;
    }
    ans += DFS(j, i);
  }

  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  int root = 1;
  for(int i = 2; i <= n; ++i){
    if(a[i] < a[root]){
      root = i;
    }
  }

  for(int k = 0; k < B; ++k){
    for(int i = 0; i <= n; ++i){
      dp[k][i] = inf;
    }
  }

  printf("%lld\n", DFS(root));

  return 0;
}