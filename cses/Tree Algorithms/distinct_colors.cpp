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
#define LOGN 17

vector<vector<int>> adj(N);
int c[N], lastVertex[N], a[N], startTime[N], endTime[N], timer, ans[N];
int T[N];

void Update(int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

void Update(int l, int r, int x){
  Update(l, x);
  Update(r + 1, -x);
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

int Query(int l, int r){
  return Query(r) - Query(l - 1);
}

void UpdateVertex(int i, int x){
  if(i == 0){
    return;
  }

  x -= a[i];
  a[i] += x;
  Update(startTime[i], x);
}

ll QuerySubtree(int i){
  return Query(startTime[i], endTime[i]);
}

void DFS(int i, int p){
  startTime[i] = ++timer;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
  }

  endTime[i] = timer;

  int k = lastVertex[c[i]];
  UpdateVertex(k, 0);
  UpdateVertex(i, 1);
  lastVertex[c[i]] = i;

  ans[i] = QuerySubtree(i);
}

int main(){
  int n;
  map<int,int> M;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    auto it = M.find(x);
    if(it != M.end()){
      c[i] = it->second;
    }
    else{
      M[x] = i;
      c[i] = i;
    }
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);

  for(int i = 1; i <= n; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");
  
  return 0;
}