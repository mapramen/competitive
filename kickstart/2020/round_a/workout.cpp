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
#define N 100001

int a[N];

int GetAdditionalTrainingsCount(int n, int m){
  int ans = 0;
  for(int i = 1; i < n; ++i){
    int x = a[i + 1] - a[i] - 1;
    ans += (x / m);
  }
  return ans;
}

bool Check(int n, int m, int k){
  return GetAdditionalTrainingsCount(n, m) <= k;
}

int BinarySearch(int n, int k){
  int x = 1, y = 1;
  for(int i = 1; i < n; ++i){
    y = max(y, a[i + 1] - a[i]);
  }

  int ans = y;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(n, mid, k)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }

  return ans;
}

int Solve(){
  int n, k;

  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  return BinarySearch(n, k);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }
  return 0;
}