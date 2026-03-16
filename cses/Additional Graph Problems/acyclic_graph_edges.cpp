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
int startTime[N], endTime[N], timer;
bool visited[N];

void DFS(int i){
  if(visited[i]){
    return;
  }

  visited[i] = true;
  startTime[i] = ++timer;
  
  for(int j: adj[i]){
    DFS(j);
  }

  endTime[i] = timer;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    DFS(i);
  }

  for(int i = 1; i <= n; ++i){
    for(int j: adj[i]){
      if(startTime[i] > startTime[j]){
        continue;
      }
      printf("%d %d\n", i, j);
    }
  }

  return 0;
}