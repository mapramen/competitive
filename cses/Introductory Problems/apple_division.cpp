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
#define B 20
#define M (1 << B)

int a[B];
ll dp[M];

int main(){
  int n;
  ll s = 0;

  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    s += a[i];
  }

  for(int mask = 1; mask < (1 << n); ++mask){
    int k = __builtin_ctz(mask);
    dp[mask] = a[k] + dp[mask ^ (1 << k)];
  }

  ll ans = LLONG_MAX;
  for(int mask = 0; mask < (1 << n); ++mask){
    ans = min(ans, abs(s - 2 * dp[mask]));
  }

  cout << ans << '\n';
  
  return 0;
}