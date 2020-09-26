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
#define N 300001
#define MOD 998244353

vector<pii> a;
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

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    int l, r;
    scanf("%d%d", &l, &r);
    a.push_back({l, 1});
    a.push_back({r + 1, -1});
  }
  sort(a.begin(), a.end());

  Initialise();

  int c = 0, ans = 0;
  for(auto p: a){
    int x = p.second;

    if(x == 1){
      ans = (ans + nCr(c, m - 1)) % MOD;
    }

    c += x;
  }

  printf("%d\n", ans);
  
  return 0;
}