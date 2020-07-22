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
#define N 200001

int T[N];

void Update(int i, int val){
  for( ; i < N; i += (i & -i)){
    T[i] += val;
  }
}

void Update(int l, int r, int val){
  Update(l, val);
  Update(r + 1, -val);
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  vector<pii> v;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    v.push_back({x, i});
  }
  sort(v.begin(), v.end());

  for(int i = 1; i <= n; ++i){
    Update(i, 1);
  }

  int m = n;
  ll ans = 0;
  for(auto p: v){
    int i = p.second;
    int ci = Query(i);
    ans += min(ci - 1, m - ci);
    Update(i + 1, n, -1);
    --m;
  }

  printf("%lld\n", ans);

  return 0;
}