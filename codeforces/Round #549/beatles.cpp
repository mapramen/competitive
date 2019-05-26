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

ll ansMin = LLONG_MAX, ansMax = LLONG_MIN;

void Solve(int n, int k, int a, int b){
  ll m = 1ll * n * k;
  for(ll x = (b - a) % k; x <= m; x += k){
    if(x <= 0){
      continue;
    }
    ll ans = m / __gcd(m, x);
    ansMin = min(ansMin, ans);
    ansMax = max(ansMax, ans);
  }
}

int main(){
  int n, k, a, b;

  cin >> n >> k >> a >> b;
  
  Solve(n, k, a, b);
  Solve(n, k, a, k - b);
  Solve(n, k, k - a, b);
  Solve(n, k, k - a, k - b);

  cout << ansMin << ' ' << ansMax << '\n';

  return 0;
}