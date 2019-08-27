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
#define MOD 998244353

vector< vector<int> > adj(N);
ll dp[N][2];

void DFS(int i){
  if(adj[i].empty()){
    dp[i][0] = 1, dp[i][1] = 1;
    return;
  }

  ll a = 0, b = 1, c = 0;

  for(int j : adj[i]){
    DFS(j);
    
    int x = dp[j][0], y = dp[j][1];
    c = (c * (x + y) + a * x) % MOD;
    a = (b * x + a * y) % MOD;
    b = (b * y) % MOD;
  }

  dp[i][0] = (a + c) % MOD, dp[i][1] = (b + c) % MOD;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int j = 2; j <= n; ++j){
    int i;
    scanf("%d", &i);
    adj[i].push_back(j);
  }

  DFS(1);
  printf("%lld\n", dp[1][1]);

  return 0;
}