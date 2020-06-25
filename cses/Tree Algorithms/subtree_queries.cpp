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
int a[N], startTime[N], endTime[N], timer;
ll T[N];

void Update(int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

ll Query(int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

ll Query(int l, int r){
  return Query(r) - Query(l - 1);
}

void UpdateVertex(int i, int x){
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

  int x = a[i];
  a[i] = 0;
  UpdateVertex(i, x);
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);

  while(q--){
    int k, i;
    scanf("%d%d", &k, &i);

    if(k == 1){
      int x;
      scanf("%d", &x);
      UpdateVertex(i, x);
    }
    else{
      printf("%lld\n", QuerySubtree(i));
    }
  }
  
  return 0;
}