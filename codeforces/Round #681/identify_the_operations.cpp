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
#define N 200002
#define MOD 998244353

int a[N], idx[N];

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);
  
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    idx[x] = i;
  }

  a[0] = n + 1, a[n + 1] = n + 1;
  for(int i = 1; i <= n; ++i){
    a[i] = 0;
  }

  for(int j = 1; j <= m; ++j){
    int x;
    scanf("%d", &x);
    int i = idx[x];
    a[i] = j;
  }

  for(int i = 1; i <= n; ++i){
    if(a[i] != 0 && a[i] < a[i - 1] && a[i] < a[i + 1]){
      return 0;
    }
  }

  int ans = 1;
  for(int i = 1; i <= n; ){
    if(a[i] == 0){
      ++i;
      continue;
    }

    int c = i != 1;
    for( ; i <= n && a[i] != 0; ++i);
    c += (i <= n);

    ans = (c * ans) % MOD;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}