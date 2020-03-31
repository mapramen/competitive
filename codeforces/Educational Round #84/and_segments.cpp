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
#define N 500005
#define MOD 998244353

int l[N], r[N], x[N], a[N], f[N], c[N], dp[N];

int SolveOneBit(int n, int m){
  for(int i = 1; i <= n + 1; ++i){
    f[i] = 0;
    c[i] = 0;
  }

  for(int i = 1; i <= m; ++i){
    if(a[i] == 0){
      f[r[i] + 1] = max(f[r[i] + 1], l[i]);
    }
    else{
      ++c[l[i]], --c[r[i] + 1];
    }
  }

  for(int i = 1; i <= n + 1; ++i){
    c[i] += c[i - 1];
    f[i] = max(f[i], f[i - 1]);
  }

  dp[0] = 1;
  for(int i = 1, j = 0, s = 1; i <= n + 1; ++i){
    if(c[i]){
      dp[i] = 0;
    }
    else{
      for( ; j < f[i]; ++j){
        s = (s - dp[j]) % MOD;
      }
      dp[i] = s;
    }

    s = (s + dp[i]) % MOD;
  }

  return (MOD + dp[n + 1]) % MOD;
}

int main(){
  int n, k, m;

  scanf("%d%d%d", &n, &k, &m);

  for(int i = 1; i <= m; ++i){
    scanf("%d%d%d", &l[i], &r[i], &x[i]);
  }

  int ans = 1;
  while(k-- && ans > 0){
    for(int i = 1; i <= m; ++i){
      a[i] = x[i] % 2;
      x[i] /= 2;
    }

    ans = (1ll * ans * SolveOneBit(n, m)) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}