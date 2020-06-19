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

pii a[N];

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i].first, &a[i].second);
  }
  sort(a + 1, a + n + 1);

  ll ans = 0, t = 0;
  for(int i = 1; i <= n; ++i){
    auto [x, d] = a[i];
    t += x;
    ans += (d - t);
  }

  printf("%lld\n", ans);
  
  return 0;
}