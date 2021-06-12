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
#define N 1000001
#define MOD 1000000007

ll fact[N], inv_fact[N];

int ModExp(int a, int n){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 != 0){
      ans = (1ll * ans * a) % MOD;
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
    fact[i] = (i * fact[i - 1]) % MOD;
  }

  inv_fact[N - 1] = ModInv(fact[N - 1]);
  for(int i = N - 2; i > -1; --i){
    inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % MOD;
  }
}

int nCr(int n, int r){
  if(n < 0 || r < 0 || n < r){
    return 0;
  }

  return (fact[n] * ((inv_fact[r] * inv_fact[n - r]) % MOD)) % MOD;
}

int main(){
  int n;
  scanf("%d", &n);

  Initialise();

  int ans = 0;
  for(int x = 0; x <= n; x += 2){
    int ansx = (nCr(x, n - x) + nCr(x - 1, n - x - 1)) % MOD;
    ans = (ans + 2 * ansx * fact[x]) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}