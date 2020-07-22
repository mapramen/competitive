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
#define tiii tuple<int,int,int>
#define N 200001

int a[N];
set<int> S;
priority_queue<tiii,vector<tiii>,greater<tiii>> Q;

int GetLower(int i){
  return i < *S.begin() ? *S.rbegin() : *prev(S.upper_bound(i));
}

int GetUpper(int i){
  return *S.rbegin() < i ? *S.begin() : *S.upper_bound(i);
}

int GetDis(int n, int i, int j){
  int d = (n + i - j) % n;
  return min(d, n - d);
}

int GetSink(int n, int i){
  int l = GetLower(i), r = GetUpper(i);
  return make_pair(GetDis(n, i, l), a[l]) < make_pair(GetDis(n, i, r), a[r]) ? l : r;
}

int GetMinDis(int n, int i){
  return GetDis(n, i, GetSink(n, i));
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    a[i] = x - a[i];
  }

  for(int i = 1; i <= n; ++i){
    if(a[i] < 0){
      S.insert(i);
    }
  }

  for(int i = 1; i <= n; ++i){
    if(a[i] > 0){
      Q.push({a[i], GetMinDis(n, i), i});
      a[i] = 0;
    }

    if(a[i] < 0){
      a[i] = -a[i];
    }
  }

  ll ans = 0;
  while(!Q.empty()){
    auto [x, y, i] = Q.top();
    Q.pop();

    int j = GetSink(n, i);
    int z = min(x, a[j]);

    ans += 1ll * z * GetDis(n, i, j);

    if(z != a[j]){
      a[j] -= z;
    }
    else{
      S.erase(j);
    }

    if(z != x){
      Q.push({x - z, GetMinDis(n, i), i});
    }
  }

  printf("%lld\n", ans);

  return 0;
}