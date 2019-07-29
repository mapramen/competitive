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
#define N 300001

int a[N];
ll prefixDp[N][2];

int main(){
  int n;
  ll x;

  scanf("%d%lld", &n, &x);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    prefixDp[i][0] = max(0ll, a[i] + prefixDp[i - 1][0]);
    prefixDp[i][1] = max(prefixDp[i][0], x * a[i] + prefixDp[i - 1][1]);
  }

  ll suffixAns = 0, ans = 0;
  for(int i = n; i > 0; --i){
    ll ansx = prefixDp[i][1] + suffixAns;
    ans = max(ans, ansx);
    suffixAns = max(0ll, a[i] + suffixAns);
  }

  printf("%lld\n", ans);

  return 0;
}