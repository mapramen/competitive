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
  int n;
  ll ans = LLONG_MIN, s = 0;

  scanf("%d", &n);
  while(n--){
    int x;
    scanf("%d", &x);
    s = max(0ll, s) + x;
    ans = max(ans, s);
  }

  printf("%lld\n", ans);
  
  return 0;
}