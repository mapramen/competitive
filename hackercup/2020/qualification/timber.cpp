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
#define N 800001
#define M (2 * N)

pii a[N];
vector<int> C, dp;

void Reset(){
  C.clear();
  dp.clear();
}

int ReadInput(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i].first, &a[i].second);
  }
  sort(a + 1, a + n + 1);

  return n;
}

int GetCompressedValue(int x){
  return lower_bound(C.begin(), C.end(), x) - C.begin();
}

void Initialise(int n){
  Reset();

  for(int i = 1; i <= n; ++i){
    int p = a[i].first, h = a[i].second;
    C.push_back(p - h);
    C.push_back(p);
    C.push_back(p + h);
  }
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  dp.resize(C.size());
}

int Update(int l, int r){
  int cost = r - l;
  l = GetCompressedValue(l), r = GetCompressedValue(r);
  dp[r] = max(dp[r], cost + dp[l]);
  return dp[r];
}

int Solve(){
  int n = ReadInput();
  Initialise(n);

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    int p = a[i].first, h = a[i].second;
    ans = max(ans, Update(p, p + h));
    ans = max(ans, Update(p - h, p));
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