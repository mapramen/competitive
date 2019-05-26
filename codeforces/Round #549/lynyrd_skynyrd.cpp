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
int n, a[N], b[N], c[N], p[N], lastIndex[N], path[N], pathIndex;

void DFS(int i){
  path[pathIndex++] = i;
  for(int j : adj[i]){
    DFS(j);
  }
  c[i] = path[max(0, pathIndex - n)];
  --pathIndex;
}

int main(){
  int m, q;

  scanf("%d%d%d", &n, &m, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= m; ++i){
    scanf("%d", &b[i]);
  }

  p[a[1]] = a[n];
  for(int i = 2; i <= n; ++i){
    p[a[i]] = a[i - 1];
  }

  for(int i = 1; i <= m; ++i){
    adj[lastIndex[p[b[i]]]].push_back(i);
    lastIndex[b[i]] = i;
  }

  DFS(0);

  for(int i = 1; i <= m; ++i){
    c[i] = max(c[i], c[i - 1]);
  }

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d", l <= c[r]);
  }
  printf("\n");

  return 0;
}