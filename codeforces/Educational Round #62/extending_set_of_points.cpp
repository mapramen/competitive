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
#define state tuple< int, int, int, int, int, ll >
#define N 600001
#define B 20
#define M (1 << B)

vector< vector<int> > v(M);
int parent[N], tSize[N], xSize[N], ySize[N], qx[N], qy[N];
ll ans = 0, queryAns[N];

void Initialise(){
  for(int i = 1, n = N / 2; i < N; ++i){
    parent[i] = i;
    tSize[i] = 1;
    xSize[i] = (i <= n);
    ySize[i] = (i > n);
  }
}

int Find(int i){
  for( ; parent[i] != i; i = parent[i]);
  return i;
}

void UpdateAns(int i, int x){
  ll ansx = 1ll * xSize[i] * ySize[i];
  ans += x * ansx;
}

void PushStateToStack(int i, stack< state > &S){
  S.push(make_tuple(i, parent[i], tSize[i], xSize[i], ySize[i], ans));
  UpdateAns(i, -1);
}

void Union(int i, int j, stack< state > &S){
  i = Find(i), j = Find(j);

  if(i == j){
    return ;
  }

  if(tSize[i] < tSize[j]){
    swap(i, j);
  }

  PushStateToStack(i, S);
  PushStateToStack(j, S);

  parent[j] = i;
  tSize[i] += tSize[j];
  xSize[i] += xSize[j];
  ySize[i] += ySize[j];

  UpdateAns(i, 1);
}

void ApplyRollback(stack< state > &S){
  for( ; !S.empty(); S.pop()){
    int i = get<0>(S.top());
    tie(i, parent[i], tSize[i], xSize[i], ySize[i], ans) = S.top();
  }
}

void Update(int k, int l, int r, int ql, int qr, int x){
  if(qr < l || r < ql){
    return ;
  }

  if(ql <= l && r <= qr){
    v[k].push_back(x);
    return ;
  }

  Update(2 * k + 1, l, (l + r) / 2, ql, qr, x);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, x);
}

void Solve(int k, int l, int r){
  stack< state > S;

  for(int i : v[k]){
    Union(qx[i], qy[i], S);
  }

  if(l != r){
    Solve(2 * k + 1, l, (l + r) / 2);
    Solve(2 * k + 2, (l + r) / 2 + 1, r);
  }
  else{
    queryAns[l] = ans;
  }

  ApplyRollback(S);
}

int main(){
  int n;
  map< pii, int > pointMap;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x, y;
    scanf("%d%d", &x, &y);
    y += (N / 2);

    pii p = make_pair(x, y);

    auto it = pointMap.find(p);
    if(it == pointMap.end()){
      pointMap[p] = i;
      qx[i] = x, qy[i] = y;
    }
    else{
      int j = it->second;
      Update(0, 1, n, j, i - 1, j);
      pointMap.erase(it);
    }
  }

  for(auto q : pointMap){
    Update(0, 1, n, q.second, n, q.second);
  }

  Initialise();
  Solve(0, 1, n);

  for(int i = 1; i <= n; ++i){
    printf("%lld ", queryAns[i]);
  }
  printf("\n");

  return 0;
}