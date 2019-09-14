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
#define N 100001
#define B 3
#define M (1 << B)

int parent[N], color[N];
char s[N];

void Reset(){
  for(int i = 1; i < N; ++i){
    parent[i] = i;
  }
}

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return;
  }
  if(i > j){
    swap(i, j);
  }
  parent[j] = i;
}

void QuerySkipAdjacent(vector<int> v, int start){
  vector< pii > queries;

  for(int i = start; i + 1 < v.size(); i += 2){
    queries.push_back(make_pair(v[i], v[i + 1]));
  }

  if(queries.empty()){
    return;
  }

  printf("Q %lu ", queries.size());
  for(auto p : queries){
    printf("%d %d ", p.first, p.second);
  }
  printf("\n");
  fflush(stdout);

  scanf("%s", s);
  for(int x = 0; x < queries.size(); ++x){
    if(s[x] == '1'){
      Union(queries[x].first, queries[x].second);
    }
  }

  queries.clear();
}

void QueryAdjacent(vector<int> v){  
  QuerySkipAdjacent(v, 0);
  QuerySkipAdjacent(v, 1);
}

void Solve(int n){
  vector<int> v;
  for(int i = 1; i <= n; ++i){
    v.push_back(i);
  }
  QueryAdjacent(v);

  v.clear();
  for(int i = 1; i <= n; ++i){
    if(parent[i] == i){
      v.push_back(i);
    }
  }

  for(int parity = 0; parity < 2; ++parity){
    vector<int> u;
    for(int i = parity, x = 0; i < v.size(); i += 2){
      u.push_back(v[i]);
    }
    QueryAdjacent(u);
  }

  for(int i = 0; i < 2; ++i){
    color[v[i]] = i;
  }

  for(int i = 2; i < v.size(); ++i){
    int x = v[i];
    if(Find(x) == x){
      color[x] = (B ^ color[v[i - 1]] ^ color[v[i - 2]]);
    }
    else{
      color[x] = color[parent[x]];
    }
  }
}

void PrintAns(int n){
  vector< vector<int> > V(B);
  
  for(int i = 1; i <= n; ++i){
    color[i] = color[Find(i)];
    V[color[i]].push_back(i);
  }

  printf("A ");
  for(auto v : V){
    printf("%lu ", v.size());
  }
  printf("\n");

  for(auto v : V){
    for(int x : v){
      printf("%d ", x);
    }
    printf("\n");
  }
  fflush(stdout);
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);

    Reset();
    Solve(n);
    PrintAns(n);
  }

  return 0;
}