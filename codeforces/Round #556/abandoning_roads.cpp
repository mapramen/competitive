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
#define N 71
#define M 201
#define B 17
#define K (1 << B)
 
vector< vector<int> > edgeNos(N), lightAdj(N);
int edgeXors[M], edgeWeights[M], componentNo[N], componentMask[N], dp[K][N], totalComponents;
vector<int> component;
bool visited[N];
queue< tiii > Q;
 
void DFS(int i){
  visited[i] = 1;
  component.push_back(i);
 
  for(int j : lightAdj[i]){
    if(visited[j]){
      continue;
    }
    DFS(j);
  }
}
 
void PreProcess(int n){
  int t = 1;
  for(int i = 1; i <= n; ++i, component.clear()){
    if(visited[i]){
      continue;
    }
    
    DFS(i);
 
    for(int j : component){
      componentNo[j] = t;
    }
    ++t;
    
    if(component.size() < 4){
      continue;
    }
    
    for(int j : component){
      componentMask[j] = (1 << totalComponents);
    }
 
    ++totalComponents;
  }
}
 
void inline CheckAndPushToQueue(int mask, int i, int di){
  if(di < dp[mask][i]){
    dp[mask][i] = di;
    Q.push(make_tuple(mask, i, di));
  }
}
 
int main(){
  int n, m, a, b;
  cin >> n >> m >> a >> b;
 
  for(int x = 1; x <= m; ++x){
    int i, j, k;
    cin >> i >> j >> k;
    
    edgeXors[x] = (i ^ j);
    edgeWeights[x] = k;
    edgeNos[i].push_back(x);
    edgeNos[j].push_back(x);
 
    if(k == a){
      lightAdj[i].push_back(j);
      lightAdj[j].push_back(i);
    }
  }
 
  PreProcess(n);
 
  for(int mask = 0; mask < (1 << totalComponents); ++mask){
    for(int i = 1; i <= n; ++i){
      dp[mask][i] = INT_MAX;
    }
  }
 
  CheckAndPushToQueue(componentMask[1], 1, 0);
 
  while(!Q.empty()){
    int mask, i, di;
    tie(mask, i, di) = Q.front();
    Q.pop();
 
    for(int edgeNo : edgeNos[i]){
      int j = (edgeXors[edgeNo] ^ i);
      int k = edgeWeights[edgeNo];
      int nmask = (mask | componentMask[j]);
 
      if(k == b && (componentNo[i] == componentNo[j] || (componentMask[j] && mask == nmask))){
        continue;
      }
 
      int dj = di + k;
      CheckAndPushToQueue(nmask, j, dj);
    }
  }
 
  for(int i = 1; i <= n; ++i){
    int ans = INT_MAX;
    for(int mask = 0; mask < (1 << totalComponents); ++mask){
      ans = min(ans, dp[mask][i]);
    }
    cout << ans << ' ';
  }
  cout << '\n';
 
  return 0;
}