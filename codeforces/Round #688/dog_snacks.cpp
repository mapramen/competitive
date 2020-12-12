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

vector<vector<int>> adj(N);

pii Combine(int ans, bool needToMerge, vector<int> &h){
  if(h.empty()){
    return {0, 0};
  }

  auto it = max_element(h.begin(), h.end());
  int hm = *it;
  h.erase(it);

  if(h.empty()){
    ans = max(ans, hm);
    return {ans, hm};
  }

  if(needToMerge){
    ans = max(ans, hm + 1);
    hm = *min_element(h.begin(), h.end());
  }
  else{
    ans = max(ans, max(hm, 1 + (*max_element(h.begin(), h.end()))));
  }

  h.clear();
  return {ans, hm};
}

pii DFS(int i, int p){
  vector<int> h;
  int ans = 0, c = adj[i].size() - (p != 0);

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    
    auto [ansx, hx] = DFS(j, i);
    ans = max(ans, ansx);
    h.push_back(hx + 1);
  }

  adj[i].clear();

  return Combine(ans, p != 0, h);
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  return DFS(1, 0).first;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}