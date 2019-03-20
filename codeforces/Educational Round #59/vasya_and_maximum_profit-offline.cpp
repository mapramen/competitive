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

#define pii pair<int, int>
#define pll pair<ll, ll>
#define PB push_back
#define MP make_pair

template <typename T>
struct RMQ{
  int n = 0, levels = 0;
  vector<T> values;
  vector<vector<int>> indexTable;

  RMQ(const vector<T> &_values = {}, bool isMinimum = true){
    if (!_values.empty()){
      Build(_values, isMinimum);
    }
  }

  static int LargestBit(int x){
    return 31 - __builtin_clz(x);
  }

  int MaxIndex(int a, int b) const{
    return values[a] > values[b] ? a : b;
  }

  void Build(const vector<T> &_values, bool isMininum){
    values = _values;
    n = values.size();
    levels = LargestBit(n) + 1;
    indexTable.resize(levels);

    if(isMininum){
      for(int i = 0; i < n; ++i){
        values[i] = -values[i];
      }
    }

    for(int k = 0; k < levels; ++k){
      indexTable[k].resize(n - (1 << k) + 1);
    }

    for(int i = 0; i < n; ++i){
      indexTable[0][i] = i;
    }

    for(int k = 1; k < levels; ++k){
      for(int i = 0, j = (1 << (k - 1)), m = n - (1 << k) + 1; i < m; ++i, ++j){
        indexTable[k][i] = MaxIndex(indexTable[k - 1][i], indexTable[k - 1][j]);
      }
    }
  }

  int QueryIndex(int i, int j) const {
    assert(i <= j);
    int k = LargestBit(j - i + 1);
    return MaxIndex(indexTable[k][i], indexTable[k][j - (1 << k) + 1]);
  }

  T QueryValue(int i, int j) const{
    return values[QueryIndex(i, j)];
  }
};

vector<ll> c, d;
RMQ<ll> valMinRMQ, valMaxRMQ, diffMaxRMQ;

void PreProcess(ll a){
  int n = c.size() - 1;

  for(int i = 1; i <= n; ++i){
    c[i] = a - c[i];
  }

  for(int i = 1; i <= n; ++i){
    c[i] += c[i - 1];
  }

  valMinRMQ.Build(c, true);
  valMaxRMQ.Build(c, false);
  
  for(int i = n; i > 1; --i){
    c[i] -= c[i - 1];
    d[i] -= d[i - 1];
    d[i] *= d[i];
  }
  d[1] = 0;
  
  diffMaxRMQ.Build(d, false);
}

ll Solve(int l, int r){
  if(l > r){
    return 0ll;
  }

  if(l == r){
    return max(c[l], 0ll);
  }

  int mid = diffMaxRMQ.QueryIndex(l + 1, r);
  ll ans = max(Solve(l, mid - 1), Solve(mid, r));
  ans = max(ans, valMinRMQ.QueryValue(l - 1, mid - 1) + valMaxRMQ.QueryValue(mid, r) - d[mid]);

  return ans;
}

int main(){
  int n;
  ll a;

  scanf("%d%lld", &n, &a);

  c.resize(n + 1), d.resize(n + 1);
  for(int i = 1; i <= n; ++i){
    scanf("%lld%lld", &d[i], &c[i]);
  }

  PreProcess(a);

  ll ans = Solve(1, n);

  printf("%lld\n", ans);

  return 0;
}