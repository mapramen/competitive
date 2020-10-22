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
#define pitiii pair<int,tuple<int,int,int>>

vector<pitiii> v;
vector<int> a;

int Dis(int n, int x, int y){
  int d = abs(x - y);
  return min(d, n - d);
}

void AddSegment(int x1, int y1, int x2, int y2){
  int dx = x2 - x1, dy = y2 - y1;
  int m = dy / dx, c = y1 - m * x1;
  v.push_back({x1, {1, m, c}});
  v.push_back({x2, {-1, m, c}});
}

void Add(int n, int z, int x, int y){
  AddSegment(x, Dis(n, z, x), y, Dis(n, z, y));
}

ll Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  v.clear();
  while(n--){
    int x;
    scanf("%d", &x);

    int x1 = x - (m / 2), x2 = x + (m / 2);
    if(x1 <= 0){
      x1 += m;
    }

    if(x2 > m){
      x2 -= m;
    }

    a.clear();
    a = vector<int>{1, m, x, x1, x2};
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for(int i = 0; i < a.size() - 1; ++i){
      Add(m, x, a[i], a[i + 1]);
    }

    v.push_back({m, {1, 0, Dis(m, m, x)}});
  }

  sort(v.begin(), v.end());

  ll ans = LLONG_MAX, M = 0, C = 0;
  for(int i = 0; i < v.size(); ){
    int x = v[i].first;

    for( ; i < v.size() && v[i].first == x; ++i){
      int d, p, q;
      tie(d, p, q) = v[i].second;
      M += d * p;
      C += d * q;
    }

    ll ansx = M * x + C;
    ans = min(ans, ansx);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %lld\n", k, Solve());
  }
  return 0;
}