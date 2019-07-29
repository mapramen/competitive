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

int main(){
  int n, m;
  ll g = 0, a = 0;

  scanf("%d%d", &n, &m);

  while(n--){
    ll x;
    scanf("%lld", &x);
    if(a == 0){
      a = x;
    }
    else{
      g = gcd(g, x - a);
    }
  }

  for(int j = 1; j <= m; ++j){
    ll d;
    scanf("%lld", &d);
    if(g % d == 0){
      printf("YES\n%lld %d\n", a, j);
      return 0;
    }
  }

  printf("NO\n");
  return 0;
}