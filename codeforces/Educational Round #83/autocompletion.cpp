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
#define N 1000001
#define B 26

vector< vector<int> > adj(N), c(B);
int parent[N], parentEdgeChar[N], a[N], dp[N], setStringCount = 0;
bool isInSet[N];
vector<int> S, P;
char ch[2];

void AddToBag(int x){
  if(P.empty() || x <= P.back()){
    P.push_back(x);
  }
}

void RemoveFromBag(int x){
  if(!P.empty() && P.back() == x){
    P.pop_back();
  }
}

int Query(){
  return setStringCount + (P.empty() ? 0 : P.back());
}

void DFS(int i){
  setStringCount += isInSet[i];

  dp[i] = 1 + dp[parent[i]];
  if(isInSet[i]){
    dp[i] = min(dp[i], Query());
  }

  a[i] = dp[i] - (setStringCount - isInSet[i]);
  AddToBag(a[i]);
  
  for(int j : adj[i]){
    DFS(j);
  }

  RemoveFromBag(a[i]);
}

void PreProcess(int n){
  for(int i = 0; i <= n; ++i){
    if(adj[i].empty()){
      continue;
    }

    for(int j : adj[i]){
      c[parentEdgeChar[j]].push_back(j);
    }

    adj[i].clear();
    for(int x = 0; x < B; ++x){
      for(int j : c[x]){
        adj[i].push_back(j);
      }
      c[x].clear();
    }
  }
}

int main(){
  int n;

  scanf("%d", &n);

  for(int j = 1; j <= n; ++j){
    int i;
    scanf("%d%s", &i, ch);
    int k = ch[0] - 'a';
    parent[j] = i;
    adj[i].push_back(j);
    parentEdgeChar[j] = k;
  }

  int q;

  scanf("%d", &q);

  for(int x = 1; x <= q; ++x){
    int i;
    scanf("%d", &i);
    S.push_back(i);
    isInSet[i] = true;
  }

  PreProcess(n);

  dp[0] = -1;
  DFS(0);

  for(int i : S){
    printf("%d ", dp[i]);
  }
  printf("\n");

  return 0;
}