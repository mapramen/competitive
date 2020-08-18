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
#define N 1000001
#define B 23
#define M (1 << B)
#define MOD 1000000007

int L[N], H[N], W[N];
vector<int> X, Y;

void ReadArrayInput(int A[], int n, int k){
  for(int i = 1; i <= k; ++i){
    scanf("%d", &A[i]);
  }

  ll a, b, c, d;
  scanf("%lld%lld%lld%lld", &a, &b, &c, &d);

  for(int i = k + 1; i <= n; ++i){
    A[i] = 1 + (a * A[i - 2] + b * A[i - 1] + c) % d;
  }
}

void ReadLengths(int n, int k){
  ReadArrayInput(L, n, k);
}

void ReadHeights(int n, int k){
  ReadArrayInput(H, n, k);
}

void ReadWidths(int n, int k){
  int w;
  scanf("%d", &w);

  for(int i = 1; i <= n; ++i){
    W[i] = w;
  }
}

int ReadInputs(){
  int n, k;
  scanf("%d%d", &n, &k);
  
  ReadWidths(n, k);
  ReadLengths(n, k);
  ReadHeights(n, k);

  return n;
}

void InitialisePerimeter(){
  X.clear();
  Y.clear();

  X.resize(1);
  Y.resize(1);
}

int PerimterChange(int i){
  if(X[i - 1] + 1 != X[i]){
    return 2 * (1 + Y[i]);
  }

  return Y[i] <= Y[i - 1] ? 2 : 2 + 2 * (Y[i] - Y[i - 1]);
}

int AddRectangle(int l, int r, int y){
  int ans = 0;
  
  int i = X.size() - 1;
  for( ; i > -1 && X[i] >= l; --i){
    ans -= PerimterChange(i);
  }

  while(X.back() < r){
    int x = max(l, X.back() + 1);
    X.push_back(x);
    Y.push_back(y);
  }

  ++i;
  for( ; i < X.size(); ++i){
    Y[i] = max(Y[i], y);
    ans += PerimterChange(i);
  }

  return ans;
}

int Solve(){
  int n = ReadInputs();
  InitialisePerimeter();

  int ans = 1, perimeter = 0;
  
  for(int i = 1; i <= n; ++i){
    perimeter += AddRectangle(L[i], L[i] + W[i] - 1, H[i]);
    perimeter %= MOD;
    ans = (1ll * ans * perimeter) % MOD;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }
  return 0;
}