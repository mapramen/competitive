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
#define tiii tuple<int,int,int>
#define N 1501
#define MOD 998244353

vector<vector<int>> dp(N);
int parent[N], c[N], sz[N];
vector<tiii> edges;

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
}

vector<int> MultiplyPolynomial(vector<int> &A, vector<int> &B){
  int n = A.size(), m = B.size();
  
  vector<int> C(n + m - 1);
  for(int i = 0; i < n; ++i){
    for(int j = 0, k = i; j < m; ++j, ++k){
      C[k] = (C[k] + 1ll * A[i] * B[j]) % MOD;
    }
  }

  A.clear(), B.clear();
  return C;
}

void Merge(int i, int j){
  parent[j] = i;
  c[i] += sz[i] * sz[j];
  sz[i] += sz[j];
  
  dp[i] = MultiplyPolynomial(dp[i], dp[j]);
  
  c[j] = 0;
  sz[j] = 0;
}

void Union(int i, int j){
  i = Find(i), j = Find(j);

  if(i > j){
    swap(i, j);
  }

  if(i != j){
    Merge(i, j);
  }

  --c[i];
  if(c[i] == 0){
    dp[i][1] = (dp[i][1] + 1) % MOD;
  }
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      int k;
      scanf("%d", &k);
      if(i < j){
        edges.push_back({k, i, j});
      }
    }
  }
  sort(edges.begin(), edges.end());

  for(int i = 1; i <= n; ++i){
    parent[i] = i;
    sz[i] = 1;
    c[i] = 0;
    dp[i] = vector<int>{0, 1};
  }

  for(auto edge: edges){
    auto[k, i, j] = edge;
    Union(i, j);
  }

  for(int k = 1; k <= n; ++k){
    printf("%d ", dp[1][k]);
  }
  printf("\n");

  return 0;
}