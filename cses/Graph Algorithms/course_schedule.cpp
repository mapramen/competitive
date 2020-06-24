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
int color[N], parent[N], x, y;
vector<int> topologicalOrder;

void DFS(int i, int p){
  if(color[i] != 0){
    return;
  }

  color[i] = 1;
  parent[i] = p;

  for(int j: adj[i]){
    DFS(j, i);
    if(color[j] == 1){
      x = i, y = j;
      break;
    }
  }

  topologicalOrder.push_back(i);
  color[i] = 2;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    DFS(i, -1);
  }

  if(x != 0){
    printf("IMPOSSIBLE\n");
    return 0;
  }

  for(int i: topologicalOrder){
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}