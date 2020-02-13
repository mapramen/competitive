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
#define INV2 500000004
#define MOD 1000000007

vector< vector<int> > adj(N), C(N), T(N);
int a[N], b[N], p2[N], startTime[N], finishTime[N], timer = 0;

void PreProcessDFS(int i, int p){
  startTime[i] = ++timer;
  for(int j : adj[i]){
    if(j == p){
      continue;
    }
    PreProcessDFS(j, i);
  }
  finishTime[i] = timer;

  for(int x = startTime[i]; x < N; x += (x & -x)){
    C[x].push_back(a[i]);
  }
}

void PreProcess(int n){
  PreProcessDFS(1, 0);

  p2[0] = 1;
  for(int i = 1; i < N; ++i){
    C[i].push_back(0);
    C[i].push_back(INT_MAX);
    sort(C[i].begin(), C[i].end());
    C[i].erase(unique(C[i].begin(), C[i].end()), C[i].end());
    T[i].resize(C[i].size());
    p2[i] = (2 * p2[i - 1]) % MOD;
  }
}

void Add(int i, int x){
  for( ; i < N; i += (i & -i)){
    int j = lower_bound(C[i].begin(), C[i].end(), x) - C[i].begin();
    for( ; j < C[i].size(); j += (j & -j)){
      ++T[i][j];
    }
  }
}

int Query(int i, int x){
  int iTemp = i;
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    int j = upper_bound(C[i].begin(), C[i].end(), x) - C[i].begin() - 1;
    for( ; j > 0; j -= (j & -j)){
      ans += T[i][j];
    }
  }
  return ans;
}

int SubtreeCombinationCount(int i, int x){
  return (p2[Query(finishTime[i], x) - Query(startTime[i] - 1, x)] - 1) % MOD;
}

void DFS(int i, int p){
  for(int j : adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
  }

  const int x = a[i];
  int ans = SubtreeCombinationCount(i, x - 1);
  for(int j : adj[i]){
    if(j == p){
      continue;
    }
    ans = (ans - SubtreeCombinationCount(j, x - 1)) % MOD;
  }

  b[i] = (MOD + ans) % MOD;
  Add(startTime[i], a[i]);
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

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  PreProcess(n);
  DFS(1, 0);

  ll ans = MOD - 1;
  for(int i = 1; i <= n; ++i){
    ans = (ans + 1ll * (i - 1) * b[i]) % MOD;
  }

  for(int i = 1; i <= n; ++i){
    ans = (INV2 * ans) % MOD;
  }

  ans = (1 + ans) % MOD;

  printf("%lld\n", ans);

  return 0;
}