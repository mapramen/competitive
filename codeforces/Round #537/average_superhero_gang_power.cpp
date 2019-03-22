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
#define N 100001

ll a[N];

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &k, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  sort(a + 1, a + n + 1);

  for(int i = 1; i <= n; ++i){
    a[i] += a[i - 1];
  }

  ll s = a[n];
  double ans = 0;
  for(int i = 0; i <= min(m, n - 1); ++i){
    double ansx = s - a[i] + min(1ll * (n - i) * k, 0ll + m - i);
    ansx /= (n - i);
    ans = max(ans, ansx);
  }

  printf("%.15lf\n", ans);
  
  return 0;
}