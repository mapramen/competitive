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
#define N 6001

pll a[N];
int groupNo[N], reachableMask[N][N];
vector<ll> C;

void AddToCoordinateCompress(ll x, ll t){
  C.push_back(x);
  C.push_back(x - t);
  C.push_back(x + t);
}

int InitialiseCoordinateCompress(int n, ll t){
  C.clear();
  for(int i = 1; i <= n; ++i){
    AddToCoordinateCompress(a[i].first, t);
    AddToCoordinateCompress(a[i].second, t);
  }
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());
  return C.size();
}

int GetCompressedValue(ll x){
  return lower_bound(C.begin(), C.end(), x) - C.begin();
}

bool IsNeighbour(ll t, int i, int j){
  if(a[i].first == a[j].first){
    return abs(a[i].second - a[j].second) <= t;
  }
  
  if(a[i].second == a[j].second){
    return abs(a[i].first - a[j].first) <= t;
  }

  return false;
}

void DFS(int n, ll t, int g, int i){
  if(groupNo[i] != 0){
    return;
  }

  groupNo[i] = g;

  for(int j = 1; j <= n; ++j){
    if(!IsNeighbour(t, i, j)){
      continue;
    }
    DFS(n, t, g, j);
  }
}

int MarkHorizontal(ll t, int g, ll x, ll y){
  int l = GetCompressedValue(x - t), r = GetCompressedValue(x + t), cy = GetCompressedValue(y);
  int mask = (1 << g);
  int ans = mask;
  for(int cx = l; cx <= r; ++cx){
    reachableMask[cx][cy] |= mask;
    ans = max(ans, reachableMask[cx][cy]);
  }
  return ans;
}

int MarkVertical(ll t, int g, ll x, ll y){
  int l = GetCompressedValue(y - t), r = GetCompressedValue(y + t), cx = GetCompressedValue(x);
  int mask = (1 << g);
  int ans = mask;
  for(int cy = l; cy <= r; ++cy){
    reachableMask[cx][cy] |= mask;
    ans = max(ans, reachableMask[cx][cy]);
  }
  return ans;
}

bool Check(int n, ll t){
  for(int i = 1; i <= n; ++i){
    groupNo[i] = 0;
  }

  int g = 0;
  for(int i = 1; i <= n && g <= 4; ++i){
    DFS(n, t, g + 1, i);
    if(groupNo[i] == g + 1){
      ++g;
    }
  }

  if(g > 4){
    return false;
  }

  if(g == 1){
    return true;
  }

  int m = InitialiseCoordinateCompress(n, t);

  for(int x = 0; x < m; ++x){
    for(int y = 0; y < m; ++y){
      reachableMask[x][y] = 0;
    }
  }

  for(int i = 1; i <= n; ++i){
    int ans = max(MarkHorizontal(t, groupNo[i], a[i].first, a[i].second), MarkVertical(t, groupNo[i], a[i].first, a[i].second));
    if(__builtin_popcount(ans) == g){
      return true;
    }
  }

  return false;
}

ll BinarySearch(int n){
  ll l = 0, r = 3E9, ans = -1;
  while(l <= r){
    ll mid = l + (r - l) / 2;
    if(Check(n, mid)){
      ans = mid, r = mid - 1;
    }
    else{
      l = mid + 1;
    }
  }
  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%lld%lld", &a[i].first, &a[i].second);
  }

  printf("%lld\n", BinarySearch(n));

  return 0;
}