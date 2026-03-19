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

map<vector<int>,int> M;

vector<vector<int>> ReadTree(int n){
  vector<vector<int>> adj(n + 1);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  return adj;
}

int VectorToInt(vector<int> &v){
  sort(v.begin(), v.end());

  auto it = M.find(v);
  if(it != M.end()){
    return it->second;
  }
  int x = M.size();
  M[v] = x;
  return x;
}

int DFS(vector<vector<int>> &adj, int i, int p){
  vector<int> v;
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    v.push_back(DFS(adj, j, i));
  }
  return VectorToInt(v);
}

bool Solve(){
  int n;
  scanf("%d", &n);

  vector<vector<int>> adj1 = ReadTree(n);
  vector<vector<int>> adj2 = ReadTree(n);

  return DFS(adj1, 1, 0) == DFS(adj2, 1, 0);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}