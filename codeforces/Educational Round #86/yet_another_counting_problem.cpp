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

vector<int> v;

ll Query(ll x, int n){
  ll ans = (x / n) * (v.size() - 1);
  x %= n;

  ans += (upper_bound(v.begin(), v.end(), x) - v.begin());

  return ans;
}

void Solve(){
  int a, b, t;

  scanf("%d%d%d", &a, &b, &t);

  int c = a * b;

  for(int x = 1; x <= c; ++x){
    if((x % a) % b != (x % b) % a){
      v.push_back(x);
    }
  }
  v.push_back(c + 1);

  while(t--){
    ll l, r;
    scanf("%lld%lld", &l, &r);
    printf("%lld ", Query(r, c) - Query(l - 1, c));
  }
  printf("\n");

  v.clear();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}