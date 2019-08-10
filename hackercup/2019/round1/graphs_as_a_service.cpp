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
#define tiii tuple< int, int, int >
#define N 51

int a[N][N];
const int inf = 1E9;
vector< tiii > edges;

void Solve(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      a[i][j] = inf;
    }
    a[i][i] = 0;
  }

  edges.clear();
  while(m--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    edges.push_back(make_tuple(i, j, k));
    a[i][j] = a[j][i] = k;
  }

  for(int k = 1; k <= n; ++k){
    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= n; ++j){
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }

  for(auto edge : edges){
    int i, j, k;
    tie(i, j, k) = edge;
    if(a[i][j] < k){
      printf("Impossible\n");
      return ;
    }
  }

  printf("%lu\n", edges.size());
  for(auto edge : edges){
    int i, j, k;
    tie(i, j, k) = edge;
    printf("%d %d %d\n", i, j, k);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: ", k);
    Solve();
  }
  return 0;
}