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

void DFS(int i){
  for(int j: adj[i]){
    DFS(j);
    dp[i] += (1 + dp[j]);
  }
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

  for(int i = 1; i <= n; ++i){
    printf("%d ", dp[i]);
  }
  printf("\n");
  
  return 0;
}