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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define N 200001

int parent[N];
vector< tiii > edges;

int Find(int i){
  return i == parent[i] ? i : Find(parent[i]);
}

bool Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return false;
  }
  if(i > j){
    swap(i, j);
  }
  parent[j] = i;
  return true;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int x = 1; x <= m; ++x){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    edges.push_back(make_tuple(k, i, j));
  }

  sort(edges.begin(), edges.end());

  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }

  int ans = 0;
  for(int x = 0; x < m; ++x){
    int w, it, jt, y;
    vector< pii > v;
    
    tie(w, it, jt) = edges[x];

    for(y = x; y < m; ++y){
      int wx, ix, jx;
      tie(wx, ix, jx) = edges[y];
      if(wx != w){
        break;
      }
      if(Find(ix) != Find(jx)){
        v.push_back(make_pair(ix, jx));
      }
    }

    for(pii p : v){
      int i, j;
      tie(i, j) = p;
      ans += !Union(i, j);
    }

    x = y - 1;
  }

  printf("%d\n", ans);

  return 0;
}