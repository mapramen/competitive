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
#define pcl pair<char,ll>
#define tllll tuple<ll,ll,ll,ll>
#define N 100005

char ch[2];
vector<tllll> a;
vector<ll> C;
vector<pcl> v;

vector<vector<pii>> updates(N), queries(N);
int T[N];

void Update(int i, int val){
  for( ; i < N; i += (i & -i)){
    T[i] += val;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

void ReadInput(){
  int n;
  char lastMove = '-';

  scanf("%d", &n);

  while(n--){
    int x;
    scanf("%s%d", ch, &x);
    char c = ch[0];

    if(!v.empty() && v.back().first == ch[0]){
      v.back().second += x;
      continue;
    }

    if((c == 'U' && lastMove == 'D')
      || (c == 'D' && lastMove == 'U')
      || (c == 'L' && lastMove == 'R')
      || (c == 'R' && lastMove == 'L'))
    {
      break;
    }

    v.push_back({c, x});
    lastMove = c;
  }

  ll x1 = 0, y1 = 0;
  a.push_back({0, 0, 0, 0});

  for(auto p: v){
    auto [c, d] = p;
    ll x2 = x1, y2 = y1;

    if(c == 'U'){
      y2 += d;
    }
    else if(c == 'D'){
      y2 -= d;
    }
    else if(c == 'R'){
      x2 += d;
    }
    else{
      x2 -= d;
    }

    a.push_back({x1, y1, x2, y2});
    x1 = x2, y1 = y2;
  }
}

int GetCompressedCoordinate(ll x){
  return lower_bound(C.begin(), C.end(), x) - C.begin();
}

ll GetOriginalValue(int i){
  return C[i];
}

int CompressCoordinates(){
  C.push_back(INT_MIN);
  for(auto t: a){
    auto [x1, y1, x2, y2] = t;
    C.push_back(x1), C.push_back(y1);
    C.push_back(x2), C.push_back(y2);
  }
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  for(int i = 0; i < a.size(); ++i){
    auto [x1, y1, x2, y2] = a[i];
    a[i] = {GetCompressedCoordinate(x1), GetCompressedCoordinate(y1), GetCompressedCoordinate(x2), GetCompressedCoordinate(y2)};
  }

  return C.size();
}

bool Check(int n){
  for(int i = 0; i <= n; ++i){
    auto [x1, y1, x2, y2] = a[i];

    if(x2 < x1){
      swap(x1, x2);
    }

    if(y2 < y1){
      swap(y1, y2);
    }

    if(x1 == x2){
      queries[x1].push_back({y1 - 1, -1});
      queries[x2].push_back({y2, 1});
    }
    
    if(y1 == y2){
      updates[x1].push_back({y1, 1});
      updates[x2 + 1].push_back({y2, -1});
    }
  }

  int m = -2;

  for(int i = 0; i < N && m < n; ++i){
    for(auto update: updates[i]){
      Update(update.first, update.second);
    }

    for(auto query: queries[i]){
      m += query.second * Query(query.first);
    }
  }

  for(int i = 0; i < N; ++i){
    updates[i].clear();
    queries[i].clear();
    T[i] = 0;
  }

  // printf("n = %d m = %d\n", n, m);

  return m >= n;
}

int BinarySearch(){
  int x = 0, y = a.size() - 1, ans = y + 1;

  while(x <= y){
    int m = x + (y - x) / 2;
    if(Check(m)){
      ans = m, y = m - 1;
    }
    else{
      x = m + 1;
    }
  }

  return ans;
}

void Initialise(){
  ReadInput();
  CompressCoordinates();
}

ll Dis(int i, int j){
  return abs(GetOriginalValue(i) - GetOriginalValue(j));
}

int main(){
  Initialise();
  int n = BinarySearch();

  ll ans = 0;
  for(int i = 0; i < n; ++i){
    auto [x1, y1, x2, y2] = a[i];
    ans += Dis(x1, x2) + Dis(y1, y2);
  }

  // printf("n = %d ans = %lld\n", n, ans);

  if(n != a.size()){
    auto [x1, y1, x2, y2] = a[n];
    bool swapAxis = x1 == x2;

    if(swapAxis){
      swap(x1, y1);
      swap(x2, y2);
    }

    ll ansx = LLONG_MAX;

    for(int i = 0; i < n - 1; ++i){
      auto [a1, b1, a2, b2] = a[i];

      if(swapAxis){
        swap(a1, b1);
        swap(a2, b2);
      }

      if(max(a1, a2) < min(x1, x2) 
        || max(x1, x2) < min(a1, a2)
        || max(y1, y2) < min(b1, b2)
        || max(b1, b2) < min(y1, y2)){
        continue;
      }

      ansx = min(ansx, Dis(x1, a1));
    }

    ans += ansx;
  }

  printf("%lld\n", ans);

  return 0;
}