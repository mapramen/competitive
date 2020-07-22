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
#define N 100001

vector<vector<int>> adj(N), V(N);
vector<pii> ans;

void DFS(int i, int p){
  if(adj[i].size() == 1){
    V[i].push_back(i);
    return;
  }

  vector<int> v;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    
    DFS(j, i);
    
    for(int x: V[j]){
      v.push_back(x);
    }

    if(v.size() <= 2){
      continue;
    }

    int x = v.size() - 1;
    swap(v[x - 1], v[x - 2]);

    ans.push_back({v[x], v[x - 1]});
    v.pop_back(), v.pop_back();
  }

  V[i] = v;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  int root = 1;
  for( ; adj[root].size() == 1; ++root);

  DFS(root, 0);

  if(V[root].size() == 1){
    ans.push_back({V[root].back(), root});
  }
  else{
    ans.push_back({V[root].front(), V[root].back()});
  }

  printf("%lu\n", ans.size());
  for(pii p: ans){
    printf("%d %d\n", p.first, p.second);
  }

  return 0;
}