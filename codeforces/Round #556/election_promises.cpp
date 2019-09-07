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
#define N 200001

vector< vector<int> > adj(N);
int c[N], mex[N], h[N], b[N];

void DFS(int i){
  for(int j : adj[i]){
    if(mex[j] >= 0){
      continue;
    }
    DFS(j);
  }

  for(int j : adj[i]){
    c[mex[j]] = i;
  }

  int &k = mex[i];
  for(k = 0; c[k] == i; ++k);
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &h[i]);
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
  }

  for(int i = 1; i <= n; ++i){
    mex[i] = -1;
  }

  for(int i = 1; i <= n; ++i){
    if(mex[i] >= 0){
      continue;
    }
    DFS(i);
  }

  for(int i = 1; i <= n; ++i){
    b[mex[i]] ^= h[i];
  }

  int root = 0;
  mex[root] = -1;
  for(int i = 1; i <= n; ++i){
    if(mex[i] > mex[root] && ((b[mex[i]] ^ h[i]) < h[i])){
      root = i;
    }
  }

  bool win = false;
  for(int i = 0; i <= mex[root] && !win; ++i){
    win = (b[i] != 0);
  }

  if(!win){
    printf("LOSE\n");
    return 0;
  }

  c[mex[root]] = root;
  for(int j : adj[root]){
    c[mex[j]] = j;
  }

  for(int i = 0; i <= mex[root]; ++i){
    int j = c[i];
    h[j] ^= b[i];
  }

  printf("WIN\n");
  for(int i = 1; i <= n; ++i){
    printf("%d ", h[i]);
  }
  printf("\n");

  return 0;
}