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

ll Solve(){
  int n;
  scanf("%d", &n);

  int m = 0;
  ll s = 0;
  for(int i = 0; i < n; ++i){
    int x;
    scanf("%d", &x);
    s += x;
    m = max(m, x);
  }
  
  m = max(1ll * m, (s + n - 2) / (n - 1));

  return 1ll * m * (n - 1) - s;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}