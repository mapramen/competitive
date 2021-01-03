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
#define B 9
#define M (1 << B)
#define MOD 998244353

vector<vector<int>> adj(N);
int g[N], c[M], A[M][M + 1];
bool visited[N];

int ModExp(int a, int n){
  int ans = 1;
  while(n > 0){
    if(n % 2 == 1){
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
    n /= 2;
  }
  return ans;
}

int ModInverse(int a){
  return ModExp(a, MOD - 2);
}

int DFS(int i){
  if(visited[i]){
    return g[i];
  }

  visited[i] = true;
  set<int> s;

  for(int j: adj[i]){
    s.insert(DFS(j));
  }

  int k = 0;
  for( ; s.count(k) > 0; ++k);
  s.clear();

  g[i] = k;
  return k;
}

void Initialise(int n){
  int m = 0;
  for(int i = 1; i <= n; ++i){
    int k = DFS(i);
    ++c[k];
    m = max(m, k);
  }

  m = (1 << (32 - __builtin_clz(m)));
  int invn = ModInverse(n + 1);

  for(int i = 0; i < m; ++i){
    for(int j = 0; j < m; ++j){
      A[i][j] = (1ll * c[(i ^ j)] * invn) % MOD;
    }
    if(i != 0){
      A[i][M] = -invn;
    }
    --A[i][i];
  }

  for(int i = m; i < M; ++i){
    A[i][i] = 1;
  }
}

void GaussJordanElimination(){
  for(int i = 0; i < M; ++i){
    for(int j = i, x = ModInverse(A[i][i]); j <= M; ++j){
      A[i][j] = (1ll * x * A[i][j]) % MOD;
    }

    for(int k = 0; k < M; ++k){
      if(k == i){
        continue;
      }
      for(int j = i, x = A[k][i]; j <= M; ++j){
        A[k][j] = (A[k][j] - 1ll * x * A[i][j]) % MOD;
      }
    }
  }
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
  }

  Initialise(n);
  GaussJordanElimination();

  int ans = (MOD + A[0][M]) % MOD;

  printf("%d\n", ans);

  return 0;
}