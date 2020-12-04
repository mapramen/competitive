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
#define N 2002

pii a[N];
int prefixAns[N], suffixAns[N];

int GetCount(int l1, int r1, int l2, int r2){
  return max(0, min(r1, r2) - max(l1, l2) + 1);
}

int main(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  for(int j = 1; j <= m; ++j){
    scanf("%d%d", &a[j].first, &a[j].second);
  }

  sort(a + 1, a + m + 1, [](pii &p, pii &q) { return p.first + p.second < q.first + q.second; });

  for(int i = 1; i <= n; ++i){
    for(int j = m, val = 0; j > 0; --j){
      val += GetCount(i, i + k - 1, a[j].first, a[j].second);
      suffixAns[j] = max(suffixAns[j], val);
    }

    for(int j = 1, val = 0; j <= m; ++j){
      val += GetCount(i, i + k - 1, a[j].first, a[j].second);
      prefixAns[j] = max(prefixAns[j], val);
    }
  }

  int ans = 0;
  for(int j = 0; j <= m; ++j){
    ans = max(ans, prefixAns[j] + suffixAns[j + 1]);
  }

  printf("%d\n", ans);

  return 0;
}