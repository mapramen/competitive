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
#define N 2000001
#define BASE 1000000
#define B 22
#define M (1 << B)

vector<vector<tiii>> V(N);

//----------------------------------------- Segment Tree -----------------------------------------//
int c[M], sum[M];

void Calculate(int k, int l, int r){
  if(l == r){
    sum[k] = (c[k] > 0);
    return;
  }

  if(c[k] != 0){
    sum[k] = (r - l + 1);
    return;
  }

  sum[k] = sum[2 * k + 1] + sum[2 * k + 2];
}

void Update(int k, int l, int r, int ql, int qr, int x){
  if(r < l || qr < l || r < ql){
    return;
  }

  if(ql <= l & r <= qr){
    c[k] += x;
    Calculate(k, l, r);
    return;
  }

  Update(2 * k + 1, l, (l + r) / 2, ql, qr, x);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, x);
  Calculate(k, l, r);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n;

  scanf("%d", &n);
  while(n--){
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1 += BASE, y1 += BASE, x2 += BASE, y2 += BASE;
    V[x1].push_back({y1, y2 - 1, 1});
    V[x2].push_back({y1, y2 - 1, -1});
  }

  ll ans = 0;
  for(int x = 0; x < N; ++x){
    for(tiii t: V[x]){
      auto [y1, y2, val] = t;
      Update(0, 0, N - 1, y1, y2, val);
    }
    ans += sum[0];
  }

  printf("%lld\n", ans);

  return 0;
}