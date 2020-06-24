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
int teamNumber[N];

bool DFS(int i){
  int ans = true;
  for(int j: adj[i]){
    if(teamNumber[j]){
      if(teamNumber[j] == teamNumber[i]){
        return false;
      }
      continue;
    }

    teamNumber[j] = 3 - teamNumber[i];
    ans = ans && DFS(j);
  }
  return ans;
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
    if(teamNumber[i]){
      continue;
    }
    
    teamNumber[i] = 1;
    if(!DFS(i)){
      printf("IMPOSSIBLE\n");
      return 0;
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", teamNumber[i]);
  }
  printf("\n");

  return 0;
}