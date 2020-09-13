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
int subtreeSize[N], parent[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    subtreeSize[i] = 0;
    parent[i] = 0;
    adj[i].clear();
  }
}

int ReadInputs(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  return n;
}

void DFS(int i, int p){
  parent[i] = p;
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
    subtreeSize[i] += subtreeSize[j];
  }
  ++subtreeSize[i];
}

int GetCentroid(int n){
  if(n % 2 == 0){
    for(int i = 1; i <= n; ++i){
      if(2 * subtreeSize[i] == n){
        return i;
      }
    }
  }

  return 1;
}

int GetOther(int i, int j){
  int ans = 0;
  for(int k: adj[j]){
    if(k != i){
      ans = k;
      break;
    }
  }
  return ans;
}

void Solve(){
  int n = ReadInputs();
  DFS(1, 0);

  int i = GetCentroid(n);

  if(i == 1){
    printf("%d %d\n", i, adj[i].front());
    printf("%d %d\n", i, adj[i].front());
  }
  else{
    int j = parent[i], k = GetOther(i, j);
    printf("%d %d\n", j, k);
    printf("%d %d\n", i, k);
  }

  Reset(n);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }  
  return 0;
}