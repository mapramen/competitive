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

ll Solve(){
  ll x, y, a, b;

  cin >> x >> y >> a >> b;
  b = min(b, 2 * a);

  if(x > y){
    swap(x, y);
  }

  ll ans = b * x;
  y -= x, x = 0;

  ans += a * y;

  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    cout << Solve() << '\n';
  }
  return 0;
}