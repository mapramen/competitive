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

vector< pll > a;

bool ShouldRemove(ll x1, ll y1, ll x2, ll y2){
  return ((double) x1) * y2 <= ((double)x2) * y1;
}

int Solve(){
  sort(a.begin(), a.end());
  vector< pll > v;

  for(auto p : a){
    if(!v.empty() && v.back().first == p.first){
      continue;
    }
    for(int i = v.size() - 1; i > 0 && ShouldRemove(p.first - v[i].first, p.second - v[i].second, v[i - 1].first - v[i].first, v[i - 1].second - v[i].second); v.pop_back(), --i);
    v.push_back(p);
  }

  return v.size() - 1;
}

int main(){
  int n;
  scanf("%d", &n);
  
  while(n--){
    ll x, y;
    scanf("%lld%lld", &x, &y);
    y = x * x - y;
    a.push_back(make_pair(x, y));
  }

  printf("%d\n", Solve());

  return 0;
}