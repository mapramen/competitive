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
#define N 10000001

ll a[N], b[N];

int main(){
  int n;
  
  scanf("%d", &n);
  
  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &b[i]);
  }

  ll ans = LLONG_MAX;
  for(int i = 1; i <= n; ++i){
    ans = min(ans, b[i] / max(1ll, a[i]));
  }

  printf("%lld\n", ans);
  
  return 0;
}