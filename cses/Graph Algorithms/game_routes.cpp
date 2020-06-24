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
#define N 100001
#define MOD 1000000007

vector<vector<int>> adj(N);
int dp[N];
bool visited[N];

int DFS(int i){
  if(visited[i]){
    return dp[i];
  }

  int ans = 0;
  for(int j: adj[i]){
    ans = (ans + DFS(j)) % MOD;
  }

  visited[i] = true;
  dp[i] = ans;

  return ans;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
  }

  visited[n] = true, dp[n] = 1;
  printf("%d\n", DFS(1));

  return 0;
}