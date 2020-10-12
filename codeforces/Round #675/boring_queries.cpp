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
#define MOD 1000000007
#define M (1 << 25)

int a[N], s[N];
vector<vector<pii>> primePowers(N), powerPositions(N);

void Initialise(){
  for(int i = 2; i < N; ++i){
    s[i] = i;
  }

  for(int i = 2; i < N; ++i){
    if(s[i] == 1){
      continue;
    }

    powerPositions[i].push_back({N, 0});

    for(int j = i; j < N; j += i){
      int k = 0, x = s[j];
      for( ; x % i == 0; ++k, x /= i);
      primePowers[j].push_back({i, s[j] / x});
      s[j] = x;
    }
  }
}

//----------------------------------------- Persistent Segment Tree -----------------------------------------//
int leftChild[M], rightChild[M], T[M];
int nxt = 0;

int NewNodeIndex(){
  return nxt++;
}

int BuildSegmentTree(int l, int r){
  int k = NewNodeIndex();
  T[k] = 1;
  if(l != r){
    leftChild[k] = BuildSegmentTree(l, (l + r) / 2);
    rightChild[k] = BuildSegmentTree((l + r) / 2 + 1, r);
  }
  return k;
}

int Update(int k, int l, int r, int ql, int qr, int x){
  if(r < ql || qr < l){
    return k;
  }

  int nk = NewNodeIndex();

  if(ql <= l && r <= qr){
    T[nk] = (1ll * x * T[k]) % MOD;
    leftChild[nk] = leftChild[k];
    rightChild[nk] = rightChild[k];
  }
  else{
    T[nk] = T[k];
    leftChild[nk] = Update(leftChild[k], l, (l + r) / 2, ql, qr, x);
    rightChild[nk] = Update(rightChild[k], (l + r) / 2 + 1, r, ql, qr, x);
  }

  return nk;
}

int Query(int k, int n, int i){
  int l = 1, r = n, ans = 1;
  while(l < r){
    int mid = (l + r) / 2;
    ans = (1ll * ans * T[k]) % MOD;
    if(i <= mid){
      k = leftChild[k], r = mid;
    }
    else{
      k = rightChild[k], l = mid + 1;
    }
  }
  return (1ll * ans * T[k]) % MOD;
}
//-------------------------------------- Persistent Segment Tree Ends --------------------------------------//

int rootIndexes[N];

void PreProcess(int n){
  Initialise();

  int k = BuildSegmentTree(1, n);
  rootIndexes[0] = k;

  for(int i = 1; i <= n; ++i){
    int x = a[i];
    
    for(auto primePower: primePowers[x]){
      auto [p, px] = primePower;
      auto &powerPosition = powerPositions[p];
      powerPosition.push_back({1, i});

      while(powerPosition.back().first < px){
        auto [val, r] = powerPosition.back();
        powerPosition.pop_back();
        k = Update(k, 1, n, powerPosition.back().second + 1, r, px / val);
      }

      powerPosition.push_back({px, i});
    }
    
    rootIndexes[i] = k;
  }
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  PreProcess(n);

  int q, ans = 0;
  scanf("%d", &q);

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    
    l = (l + ans) % n + 1, r = (r + ans) % n + 1;

    if(l > r){
      swap(l, r);
    }

    ans = Query(rootIndexes[r], n, l);

    printf("%d\n", ans);
  }

  return 0;
}