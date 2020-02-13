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
#define N 200001
#define MOD 1000000007

int a[2 * N], fact[N], invFact[N], p2[N];

int ModularExponentation(int a, int n){
  int ans = 1;
  for( ; n; n /= 2){
    if(n % 2){
      ans = (1ll * a * ans) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

int ModularInverse(int a){
  return ModularExponentation(a, MOD - 2);
}

void Initialise(){
  fact[0] = 1, p2[0] = 1;
  for(int i = 1; i < N; ++i){
    fact[i] = (1ll * i * fact[i - 1]) % MOD;
    p2[i] = (2 * p2[i - 1]) % MOD;
  }

  invFact[N - 1] = ModularInverse(fact[N - 1]);
  for(int i = N - 2; i > -1; --i){
    invFact[i] = (1ll * (i + 1) * invFact[i + 1]) % MOD;
  }
}

int Solve(){
  int n;
  ll s = 0;

  scanf("%d", &n);
  for(int i = 1; i <= 2 * n; ++i){
    scanf("%d", &a[i]);
    s += a[i];
  }

  if(s % (n + 1) != 0){
    return 0;
  }

  s /= (n + 1);

  int m = 2 * n;
  for(int k = 0; k < 2; ++k){
    int i = 1;
    for( ; i <= m && a[i] != s; ++i);
    if(i > m){
      return 0;
    }
    swap(a[i], a[m]);
    --m;
  }

  sort(a + 1, a + m + 1);

  int ans = fact[n - 1];
  for(int i = 1, j = m; i <= j; ){
    int x = a[i], y = a[j];

    if(x + y != s){
      return 0;
    }

    int cx = 0, cy = 0;
    for( ; i <= j && a[i] == x; ++i, ++cx);
    for( ; i <= j && a[j] == y; --j, ++cy);

    if(x == y){
      if(cx % 2){
        return 0;
      }
      else{
        cx /= 2, cy = cx;
      }
    }

    if(cx != cy){
      return 0;
    }

    ans = (1ll * invFact[cx] * ans) % MOD;
    if(x != y){
      ans = (1ll * p2[cx] * ans) % MOD;
    }
  }

  return ans;
}

int main(){
  int t;

  scanf("%d", &t);

  Initialise();
  while(t--){
    printf("%d\n", Solve());
  }

  return 0;
}