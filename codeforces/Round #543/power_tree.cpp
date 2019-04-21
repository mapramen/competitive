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
int parent[N], a[N], b[N], c[N], timer;

void DFS(int i, int p){
  a[i] = timer;

  for(int j : adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
  }

  if(i != 1 && adj[i].size() == 1){
    ++timer;
  }
  
  b[i] = timer;
}

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
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
  int n;
  vector< pii > v;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &c[i]);
    v.push_back(make_pair(c[i], i));
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);

  for(int i = 0; i <= timer; ++i){
    parent[i] = i;
  }

  sort(v.begin(), v.end());

  ll ans = 0;
  vector<int> ansV;

  for(int x = 0; x < n; ){
    int y;
    vector<int> u;

    for(y = x; y < n && v[y].first == v[x].first; ++y){
      int i = v[y].second;
      if(Find(a[i]) != Find(b[i])){
        u.push_back(i);
        ansV.push_back(i);
      }
    }
    x = y;

    for(int i : u){
      ans += Union(a[i], b[i]) * c[i];
    }
  }

  sort(ansV.begin(), ansV.end());
  printf("%lld %lu\n", ans, ansV.size());
  for(int i : ansV){
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}