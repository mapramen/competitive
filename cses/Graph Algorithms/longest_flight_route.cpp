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

vector<vector<int>> adj(N);
int dp[N], nxt[N];
bool visited[N];

int DFS(int i){
  if(visited[i]){
    return dp[i];
  }

  int ans = INT_MIN, k = -1;
  for(int j: adj[i]){
    int ansx = DFS(j);
    if(ansx > ans){
      ans = ansx, k = j;
    }
  }

  visited[i] = true;
  dp[i] = ++ans;
  nxt[i] = k;

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
  int ans = DFS(1);

  if(ans < 0){
    printf("IMPOSSIBLE\n");
    return 0;
  }

  printf("%d\n", ans);
  for(int x = 1; x != n; x = nxt[x]){
    printf("%d ", x);
  }
  printf("%d\n", n);

  return 0;
}