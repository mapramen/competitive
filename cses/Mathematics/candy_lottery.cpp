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
  int n, m;
  cin >> n >> m;

  double ans = 0;
  for(int i = 1; i <= m; ++i){
    ans += (1 - pow(1.0 * (i - 1) / m, n));
  }

  printf("%lf\n", ans);
  
  return 0;
}