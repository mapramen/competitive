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
#define N 2000001
#define MOD 1000000007

int fact[N], invFact[N];

int ModExp(int a, int n){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * a * ans) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans % MOD;
}

int ModInv(int a){
  return ModExp(a, MOD - 2);
}

void Initialise(){
  fact[0] = 1;
  for(int i = 1; i < N; ++i){
    fact[i] = (1ll * i * fact[i - 1]) % MOD;
  }

  invFact[N - 1] = ModInv(fact[N - 1]);
  for(int i = N - 2; i > -1; --i){
    invFact[i] = (1ll * (i + 1) * invFact[i + 1]) % MOD;
  }
}

int nCr(int n, int r){
  if(n < 0 || r < 0 || n < r){
    return 0;
  }

  int p = fact[n], q = (1ll * invFact[r] * invFact[n - r]) % MOD;
  return (1ll * p * q) % MOD;
}

int NumberOfPaths(int x, int y){
  return nCr(x + y, x);
}

int main(){
  int n, m;
  vector<pii> a;

  cin >> n >> m;
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    a.push_back({i, j});
  }
  a.push_back({n, n});

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  m = a.size();
  vector<int> dp(m);
  Initialise();

  for(int i = 0; i < m; ++i){
    int ans = 0;
    for(int j = 0; j < i; ++j){
      ans = (ans + 1ll * NumberOfPaths(a[i].first - a[j].first, a[i].second - a[j].second) * dp[j]) % MOD;
    }
    dp[i] = (NumberOfPaths(a[i].first - 1, a[i].second - 1) + MOD - ans) % MOD;
  }

  printf("%d\n", dp.back());

  return 0;
}