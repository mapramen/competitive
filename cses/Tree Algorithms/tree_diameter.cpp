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

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> adj(N);
int dp[N];

int DFS(int i, int p){
  int ans = 0;
  dp[i] = 0;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    ans = max(ans, DFS(j, i));
    ans = max(ans, 1 + dp[i] + dp[j]);
    dp[i] = max(dp[i], 1 + dp[j]);
  }

  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  printf("%d\n", DFS(1, 0));

  return 0;
}