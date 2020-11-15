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
#define tpii tuple<pii,int,int>
#define B 20
#define M (1 << B)
#define N 200002

vector<vector<int>> adj[2];
pair<int,int> dis[B + 2][N];
priority_queue<tpii,vector<tpii>,greater<tpii>> Q;

pii AddBit(pii p, int k){
  int b = p.first, x = p.second;
  
  if(k < B){
    x += (1 << k);
    k = 31 - __builtin_clz(x);
    x %= M;
  }

  if(b < B){
    b = k;
  }
  else if(b == k){
    ++b;
  }
  else{
    b = max(b, k);
  }

  return {b, x};
}

int GetX(int k){
  if(k < B){
    return k;
  }
  return B + (k % 2);
}

void CheckAndUpdate(int i, int k, pii &d){
  int x = GetX(k);
  if(d >= dis[x][i]){
    return;
  }
  dis[x][i] = d;
  Q.push({d, k, i});
}

int GetAns(int n){
  int ans = 0, MOD = 998244353;
  
  pii d = dis[0][n];
  for(int x = 1; x < B + 2; ++x){
    d = min(d, dis[x][n]);
  }

  int k = d.first;
  if(k >= B){
    ans = 1;
    for(int i = 0; i < k; ++i){
      ans = (2 * ans) % MOD;
    }
  }
  ans = (ans + d.second) % MOD;

  return ans;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  adj[0].resize(n + 1);
  adj[1].resize(n + 1);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[0][i].push_back(j);
    adj[1][j].push_back(i);
  }

  for(int x = 0; x < B + 2; ++x){
    for(int i = 1; i <= n; ++i){
      dis[x][i] = {INT_MAX, 0};
    }
  }

  pii initialDis = {0, 0};
  CheckAndUpdate(1, 0, initialDis);

  while(!Q.empty()){
    auto [d, k, i] = Q.top();
    Q.pop();

    int x = GetX(k);
    if(d != dis[x][i]){
      continue;
    }

    d = AddBit(d, 0);
    for(int j: adj[(k % 2)][i]){
      CheckAndUpdate(j, k, d);
    }

    d = AddBit(d, k);
    ++k;
    for(int j: adj[(k % 2)][i]){
      CheckAndUpdate(j, k, d);
    }
  }

  printf("%d\n", GetAns(n));

  return 0;
}