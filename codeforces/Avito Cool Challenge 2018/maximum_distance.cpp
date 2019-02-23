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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define N 100001

int c[N], parent[N];
vector< tiii > edges;

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
}

bool Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return false;
  }
  if(i > j){
    swap(j, i);
  }
  parent[j] = i;
  c[i] += c[j];
  return c[i] != c[j] && c[j] > 0;
}

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  for(int x = 1; x <= k; ++x){
    int i;
    scanf("%d", &i);
    c[i] = 1;
  }

  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    edges.push_back(make_tuple(w, i, j));
  }

  sort(edges.begin(), edges.end());

  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }

  int ans = 0;
  for(auto edge : edges){
    int i, j, w;
    tie(w, i, j) = edge;
    if(Union(i, j)){
      ans = w;
    }
  }

  for(int x = 1; x <= k; ++x){
    printf("%d ", ans);
  }
  printf("\n");
  
  return 0;
}