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
#define tiii tuple< int, int, int >
#define N 1001

int x[N], y[N];

int main(){
  int n;
  
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> x[i] >> y[i];
  }

  vector< tiii > v;
  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      int a = y[j] - y[i], b = x[j] - x[i], c = a * x[i] - b * y[i];

      if(a < 0){
        a = -a, b = -b, c = -c;
      }

      if(a == 0 && b < 0){
        b = -b, c = -c;
      }

      int g = __gcd(abs(c), __gcd(abs(a), abs(b)));
      v.push_back(make_tuple(a / g, b / g, c / g));
    }
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  ll ans = 0;
  for(int i = 0, px = 0, py = 0, j = 0; i < v.size(); ++i){
    int x, y, z;
    tie(x, y, z) = v[i];
    if(x != px || y != py){
      j = i;
    }
    ans += j;
    px = x, py = y;
  }

  printf("%lld\n", ans);

  return 0;
}