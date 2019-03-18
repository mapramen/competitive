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
#define tlii tuple< ll, int, int >
#define PB push_back
#define MP make_pair
#define N 200001

ll a[N];
int parent[N];
vector< tlii > edges;

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
  
  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  while(m--){
    int i, j;
    ll w;
    scanf("%d%d%lld", &i, &j, &w);
    if(a[i] > a[j]){
      swap(i, j);
    }
    edges.push_back(make_tuple(w, i, j));
  }


  int root = 1;
  for(int i = 1; i <= n; ++i){
    if(a[i] < a[root]){
      root = i;
    }
    parent[i] = i;
  }

  for(int i = 1; i <= n; ++i){
    if(i == root){
      continue;
    }
    edges.push_back(make_tuple(a[i] + a[root], root, i));
  }

  sort(edges.begin(), edges.end());
  
  ll ans = 0;
  for(auto edge : edges){
    int i, j;
    ll w;
    tie(w, i, j) = edge;
    ans += (w * Union(i, j));
  }

  printf("%lld\n", ans);

  return 0;
}