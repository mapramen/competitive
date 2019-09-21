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
#define MOD 998244353

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

  for(int i = 1; i <= n; ++i){
    a[i] *= (1ll * i * (n - i + 1));
  }

  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);

  ll ans = 0;
  for(int i = 1, j = n; i <= n; ++i, --j){
    a[i] %= MOD;
    ans = (ans + a[i] * b[j]) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}