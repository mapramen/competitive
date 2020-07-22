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
int c[N];
priority_queue<pli,vector<pli>,greater<pli>> Q;

void Relax(int i, ll x){
  if(c[i] != 0){
    Q.push({x, i});
  }
}

void Dijkstra(int n, int s, int t, int k){
  for(int i = 1; i <= n; ++i){
    c[i] = k;
  }

  Relax(s, 0ll);
  
  while(!Q.empty()){
    auto [di, i] = Q.top();
    Q.pop();

    if(c[i] == 0){
      continue;
    }

    --c[i];

    if(i == t){
      printf("%lld ", di);
    }

    for(pii p: adj[i]){
      Relax(p.first, di + p.second);
    }
  }
  
  printf("\n");
}

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);
  while(m--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    adj[i].push_back({j, k});
  }

  Dijkstra(n, 1, n, k);

  return 0;
}