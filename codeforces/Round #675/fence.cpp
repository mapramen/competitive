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
  ll a, b, c;
  scanf("%lld%lld%lld", &a, &b, &c);

  if(a > b){
    swap(a, b);
  }

  if(a > c){
    swap(a, c);
  }

  if(b > c){
    swap(b, c);
  }

  ll x = a * a + b * b + c * c - 2 * a * c;
  ll y = a * a + b * b + c * c + 2 * b * c;

  ll d = sqrt(x);
  for( ; d * d < x || d * d >= y; ++d);

  return d;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}