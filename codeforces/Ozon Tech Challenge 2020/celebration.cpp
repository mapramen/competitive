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
#define N 1001

vector< vector<int> > adj(N);
bool visited[N], isAsked[N], canBeRoot[N];

int GetFurthestNode(int n, int i){
  for(int j = 1; j <= n; ++j){
    visited[j] = isAsked[j];
  }
  
  queue<int> Q;
  Q.push(i);
  visited[i] = true;

  while(!Q.empty()){
    i = Q.front();
    Q.pop();

    for(int j : adj[i]){
      if(visited[j] == true){
        continue;
      }
      Q.push(j);
      visited[j] = true;
    }
  }

  return i;
}

pii GetQueryNodes(int n){
  int i;
  for(i = 1; i <= n && isAsked[i] == true; ++i);

  if(i > n){
    return make_pair(n + 1, n + 1);
  }

  i = GetFurthestNode(n, i);
  int j = GetFurthestNode(n, i);

  return make_pair(i, j);
}

int Query(int i, int j){
  printf("? %d %d\n", i, j);
  fflush(stdout);

  int k;
  scanf("%d", &k);

  isAsked[i] = true, isAsked[j] = true;

  return k;
}

void PrintAns(int i){
  printf("! %d\n", i);
  fflush(stdout);
  exit(0);
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

  for(int i = 1; i <= n; ++i){
    canBeRoot[i] = true;
  }

  while(true){
    int i, j;
    tie(i, j) = GetQueryNodes(n);

    if(i > n || i == j){
      break;
    }

    int k = Query(i, j);
    
    if(k == i || k == j){
      PrintAns(k);
    }

    canBeRoot[i] = false, canBeRoot[j] = false;
  }

  int ans = 1;
  for( ; !canBeRoot[ans]; ++ans);

  printf("! %d\n", ans);
  fflush(stdout);

  return 0;
}