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

vector<vector<pii>> adj(N);
ll d[N];
priority_queue<pli,vector<pli>,greater<pli>> Q;

void Relax(int i, ll x){
  if(x < d[i]){
    d[i] = x;
    Q.push({x, i});
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  while(m--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    adj[i].push_back({j, k});
  }

  for(int i = 1; i <= n; ++i){
    d[i] = LLONG_MAX;
  }

  Relax(1, 0ll);
  
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

  for(int i = 1; i <= n; ++i){
    printf("%lld ", d[i]);
  }
  printf("\n");

  return 0;
}