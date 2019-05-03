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
#define N 200001

ll a[N];

int main(){
  ll m, n, x = 0;

  scanf("%lld%lld", &m, &n);
  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    a[i] = a[i - 1] - a[i];
    x = max(x, a[i]);
  }

  if(a[n] <= 0 && x < m){
    printf("-1\n");
    return 0;
  }

  ll ans = (max(0ll, m - x) + a[n] - 1) / max(1ll, a[n]);
  ans = max(0ll, ans);
  m -= ans * a[n];
  ans *= n;
  for(int i = 0; i <= n; ++i){
    if(m <= a[i]){
      ans += i;
      break;
    }
  }

  printf("%lld\n", ans);

  return 0;
}