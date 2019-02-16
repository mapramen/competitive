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
#define N 300001

vector< vector<int> > adj(N);
int a[N], w[N], edgeXOR[N];
ll dp[N];

ll DFS(int i, int p = 0){
  dp[i] = a[i];
  ll ans = dp[i];
  for(auto e : adj[i]){
    int j = (i ^ edgeXOR[e]);
    if(j == p){
      continue;
    }
    ans = max(ans, DFS(j, i));
    ans = max(ans, dp[i] + dp[j] - w[e]);
    dp[i] = max(dp[i], a[i] + dp[j] - w[e]);
  }
  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int e = 1; e < n; ++e){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    edgeXOR[e] = (i ^ j);
    w[e] = k;
    adj[i].push_back(e);
    adj[j].push_back(e);
  }

  printf("%lld\n", DFS(1));
  
  return 0;
}