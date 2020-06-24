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
#define pli pair<ll,int>
#define N 100001
#define MOD 1000000007

vector<vector<pii>> adj(N);
int dpCount[N], dpMin[N], dpMax[N];
bool visited[N];
ll d[N];
priority_queue<pli,vector<pli>,greater<pli>> Q;

void Relax(int i, ll x){
  if(x < d[i]){
    d[i] = x;
    Q.push({x, i});
  }
}

void Dijkstra(int n, int s){
  for(int i = 1; i <= n; ++i){
    d[i] = LLONG_MAX;
  }

  Relax(s, 0ll);
  
  while(!Q.empty()){
    auto [di, i] = Q.top();
    Q.pop();

    if(di != d[i]){
      continue;
    }

    for(pii p: adj[i]){
      Relax(p.first, di + p.second);
    }
  }
}

void DFS(int i){
  if(visited[i]){
    return;
  }

  int ansCount = 0, ansMin = INT_MAX / 2, ansMax = INT_MIN / 2;
  for(auto p: adj[i]){
    auto [j, w] = p;
    if(d[j] != d[i] + w){
      continue;
    }
    DFS(j);
    ansCount = (ansCount + dpCount[j]) % MOD;
    ansMin = min(ansMin, dpMin[j]);
    ansMax = max(ansMax, dpMax[j]);
  }

  visited[i] = true;
  dpCount[i] = ansCount, dpMin[i] = ++ansMin, dpMax[i] = ++ansMax;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  while(m--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    adj[i].push_back({j, k});
  }

  Dijkstra(n, 1);

  visited[n] = true, dpCount[n] = 1, dpMin[n] = 0, dpMax[n] = 0;
  DFS(1);

  printf("%lld %d %d %d\n", d[n], dpCount[1], dpMin[1], dpMax[1]);

  return 0;
}