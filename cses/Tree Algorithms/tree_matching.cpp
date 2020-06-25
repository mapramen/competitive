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
int dp[2][N];

void DFS(int i, int p){
  int a = 0, b = INT_MIN;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
    int ax = max(dp[0][j], dp[1][j]);
    a += ax;
    b = max(b, dp[0][j] - ax);
  }

  dp[0][i] = a, dp[1][i] = 1 + a + b;
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

  DFS(1, 0);
  printf("%d\n", max(dp[0][1], dp[1][1]));

  return 0;
}