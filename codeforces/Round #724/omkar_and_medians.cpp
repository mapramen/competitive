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

int a[N];
set<int> S;

bool Solve(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  S.clear();
  S.insert(INT_MIN);
  S.insert(INT_MAX);

  int m = 0;
  for(int i = 1; i <= n; ++i){
    int l = *prev(S.lower_bound(m));
    int r = *S.upper_bound(m);

    m = a[i];
    if(m < l || r < m){
      return false;
    }

    S.insert(m);
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}