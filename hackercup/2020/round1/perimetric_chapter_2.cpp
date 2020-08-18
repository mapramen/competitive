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
#define MOD 1000000007

int L[N], H[N], W[N];

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
  ReadArrayInput(W, n, k);
}

int ReadInputs(){
  int n, k;
  scanf("%d%d", &n, &k);
  
  ReadLengths(n, k);
  ReadWidths(n, k);
  ReadHeights(n, k);

  return n;
}

map<int,int> xSegments;

void InitialisePerimeter(){
  xSegments.clear();
  xSegments[INT_MIN] = INT_MIN;
  xSegments[0] = INT_MAX;
  xSegments[INT_MAX] = INT_MAX;
}

int AddRectangle(int l, int r, int y){
  ll ans = 0;
  vector<int> v;
  vector<pii> a;

  auto it = prev(xSegments.upper_bound(l));

  for( ; it->first <= r; ++it){
    int x1 = it->first, x2 = it->second;
    
    if(x2 < l){
      continue;
    }

    if(x1 < l){
      a.push_back({x1, l});
      if(r < x2){
        a.push_back({r, x2});
        ans += 2 * y;
        ans += 2 * (r - l);
      }
      else{
        v.push_back(x1);
        ans += 2 * (x2 - l);
      }
    }
    else{
      v.push_back(x1);
      if(x2 <= r){
        ans -= 2 * y;
        ans += 2 * (x2 - x1);
      }
      else{
        a.push_back({r, x2});
        ans += 2 * (r - x1);
      }
    }
  }

  for(int x: v){
    xSegments.erase(x);
  }
  v.clear();

  for(auto p: a){
    xSegments[p.first] = p.second;
  }

  ans %= MOD;

  return (MOD + ans) % MOD;
}

int Solve(){
  int n = ReadInputs();
  InitialisePerimeter();

  int ans = 1, perimeter = 0;
  for(int i = 1; i <= n; ++i){
    perimeter += AddRectangle(L[i], L[i] + W[i], H[i]);
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