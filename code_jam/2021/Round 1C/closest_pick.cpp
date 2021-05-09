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

vector<pii> v;

void CheckAndPush(int l, int e){
  if(l != 0){
    v.push_back({l, e});
  }
}

int OneInterval(){
  int ans = 0;
  for(auto p: v){
    ans = max(ans, p.first);
  }
  return ans;
}

int OneInInterval(int i){
  auto [l, e] = v[i];
  if(e == 1){
    return l;
  }
  return l % 2 == 0 ? l / 2 : (l + 1) / 2;
}

int TwoIntervals(){
  int n = v.size(), ans = 0;
  for(int i = 0; i < n; ++i){
    for(int j = i + 1; j < n; ++j){
      ans = max(ans, OneInInterval(i) + OneInInterval(j));
    }
  }
  return ans;
}

double Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a;
  while(n--){
    int x;
    scanf("%d", &x);
    a.push_back(x);
  }
  
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  n = a.size();
  v.clear();

  CheckAndPush(a.front() - 1, 1);
  for(int i = 1; i < n; ++i){
    CheckAndPush(a[i] - a[i - 1] - 1, 2);
  }
  CheckAndPush(m - a.back(), 1);

  double ans = max(OneInterval(), TwoIntervals());
  return ans / m;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %.15lf\n", k, Solve());
  }
  return 0;
}