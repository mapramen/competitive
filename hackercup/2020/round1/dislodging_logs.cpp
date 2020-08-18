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
#define N 1000001

int P[N], Q[N];

void ReadArrayInput(int A[], int n, int k){
  for(int i = 1; i <= k; ++i){
    scanf("%d", &A[i]);
  }

  ll a, b, c, d;
  scanf("%lld%lld%lld%lld", &a, &b, &c, &d);

  for(int i = k + 1; i <= n; ++i){
    A[i] = 1 + (a * A[i - 2] + b * A[i - 1] + c) % d;
  }
  sort(A + 1, A + n + 1);
}

int MinimumTravellingTime(int x, int y, int z){
  if(x <= y){
    return z - x;
  }

  if(z <= x){
    return x - y;
  }

  return (z - y) + min(x - y, z - x);
}

bool IsPossible(int x, int y, int z, int t){
  return MinimumTravellingTime(x, y, z) <= t;
}

bool Check(int n, int m, int t){
  int j = 1;
  for(int i = 1; i <= n; ++i){
    int l = j, r = j;
    for( ; r <= m && IsPossible(P[i], Q[l], Q[r], t); ++r);
    j = r;
  }
  return j > m;
}

int BinarySearch(int n, int m){
  int x = 0, y = 2E9, ans = y;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(n, m, mid)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return ans;
}

int Solve(){
  int n, m, k, s;
  scanf("%d%d%d%d", &n, &m, &k, &s);
  ReadArrayInput(P, n, k);
  ReadArrayInput(Q, m, k);
  return BinarySearch(n, m);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }
  return 0;
}