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
#define N 200001

vector<vector<int>> adj(N), V(N);
int parent[N], d[N], subtreeSize[N], inf = 1E9;

//------------------------------------------------ HLD ------------------------------------------------//
int nextChainNumber = 1, chainSize[N], chainHead[N], chainNo[N], chainPosition[N];
vector<vector<int>> a(N), minConstant(N), lazyValue(N), ans(N);

void HLD(int i, int p){
  ++chainSize[chainNo[i]];
  a[chainNo[i]].push_back(-2 * d[i]);
  
  int heavyChild = 0;
  for(int j: adj[i]){
    if(j == p || subtreeSize[j] <= subtreeSize[heavyChild]){
      continue;
    }
    heavyChild = j;
  }

  for(int j: adj[i]){
    if(j == p){
      continue;
    }

    if(j == heavyChild){
      chainNo[j] = chainNo[i];
      chainPosition[j] = 1 + chainPosition[i];
    }
    else{
      chainNo[j] = nextChainNumber;
      chainHead[nextChainNumber] = j;
      ++nextChainNumber;
    }

    HLD(j, i);
  }
}

void Combine(int cNo, int k){
  ans[cNo][k] = min(ans[cNo][2 * k + 1], ans[cNo][2 * k + 2]);
}

void LazyUpdateNode(int cNo, int k, int x){
  if(x >= lazyValue[cNo][k]){
    return;
  }

  lazyValue[cNo][k] = x;
  ans[cNo][k] = min(ans[cNo][k], lazyValue[cNo][k] + minConstant[cNo][k]);
}

void BuildSegmentTree(int cNo, int k, int l, int r){
  lazyValue[cNo][k] = 2 * inf;
  ans[cNo][k] = 2 * inf;
  
  if(l == r){
    minConstant[cNo][k] = a[cNo][l];
  }
  else{
    BuildSegmentTree(cNo, 2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(cNo, 2 * k + 2, (l + r) / 2 + 1, r);
    minConstant[cNo][k] = min(minConstant[cNo][2 * k + 1], minConstant[cNo][2 * k + 2]);
    Combine(cNo, k);
  }
  
  LazyUpdateNode(cNo, k, inf);
}

void LazyUpdateChildren(int cNo, int k){
  LazyUpdateNode(cNo, 2 * k + 1, lazyValue[cNo][k]);
  LazyUpdateNode(cNo, 2 * k + 2, lazyValue[cNo][k]);
}

void Update(int cNo, int k, int l, int r, int ql, int qr, int x){
  if(r < l || qr < l || r < ql){
    return;
  }

  if(ql <= l && r <= qr){
    LazyUpdateNode(cNo, k, x);
    return;
  }

  LazyUpdateChildren(cNo, k);
  Update(cNo, 2 * k + 1, l, (l + r) / 2, ql, qr, x);
  Update(cNo, 2 * k + 2, (l + r) / 2 + 1, r, ql, qr, x);
  Combine(cNo, k);
}

int Query(int cNo, int k, int l, int r, int ql, int qr){
  if(r < l || qr < l || r < ql){
    return inf;
  }

  if(ql <= l && r <= qr){
    return ans[cNo][k];
  }

  LazyUpdateChildren(cNo, k);
  int ans1 = Query(cNo, 2 * k + 1, l, (l + r) / 2, ql, qr);
  int ans2 = Query(cNo, 2 * k + 2, (l + r) / 2 + 1, r, ql, qr);
  Combine(cNo, k);

  return min(ans1, ans2);
}

void BuildSegmentTrees(){
  chainHead[0] = 1;
  HLD(1, 0);

  for(int cNo = 0; cNo < nextChainNumber; ++cNo){
    int n = chainSize[cNo], m = 4 * n;
    minConstant[cNo].resize(m), lazyValue[cNo].resize(m), ans[cNo].resize(m);
    BuildSegmentTree(cNo, 0, 0, n - 1);
  }
}
//----------------------------------------------- HLD Ends -----------------------------------------------//

void DFS(int i, int p){
  d[i] = 1 + d[p];
  V[d[i]].push_back(i);
  parent[i] = p;
  subtreeSize[i] = 1;

  for(auto j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
    subtreeSize[i] += subtreeSize[j];
  }
}

void Update(int v){
  for(int x = d[v]; v != 0; v = parent[chainHead[chainNo[v]]]){
    Update(chainNo[v], 0, 0, chainSize[chainNo[v]] - 1, 0, chainPosition[v], x);
  }
}

int Query(int v){
  int ans = inf, x = d[v];
  for( ; v != 0; v = parent[chainHead[chainNo[v]]]){
    ans = min(ans, Query(chainNo[v], 0, 0, chainSize[chainNo[v]] - 1, 0, chainPosition[v]));
  }
  return x + ans;
}

int main(){
  int n, k;

  scanf("%d%d", &n, &k);
  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);
  BuildSegmentTrees();

  vector<int> ans;
  for(int x = n; x > 0; --x){
    for(int i: V[x]){
      if(Query(i) < k){
        continue;
      }
      ans.push_back(i);
      Update(i);
    }
  }

  printf("%lu\n", ans.size());
  for(int i: ans){
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}