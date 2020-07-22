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

int main(){
  ll n, ans = 0;

  cin >> n;
  while(n){
    int k = 0;
    while((1ll << k) - 1 <= n){
      ++k;
    }
    --k;

    ll nx = (1ll << k);
    ans += (k * (1ll << (k - 1)) + (n - nx + 1));
    n = max(0ll, n - nx);
  }

  cout << ans << '\n';

  return 0;
}