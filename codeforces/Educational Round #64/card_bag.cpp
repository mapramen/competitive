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
#define N 5001
#define MOD 998244353

int c[N];
ll dp[N], s[N];

ll ModularExponentation(ll a, int n){
  ll ans = 1;
  for( ; n; n /= 2){
    if(n % 2){
      ans = (ans * a) % MOD;
    }
    a = (a * a) % MOD;
  }
  return ans;
}

ll ModularInverse(ll a){
  return ModularExponentation(a, MOD - 2);
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ++c[x];
  }

  dp[0] = 1;
  for(int i = 1, t = 0; i <= n; ++i, t += c[i]){
    if(c[i] == 0){
      continue;
    }
    
    if(c[i] > 1){
      for(int j = 0, k = 2, val = c[i] * (c[i] - 1); j <= t; ++j, ++k){
        s[k] = (s[k] + val * dp[j]) % MOD;
      }
    }

    if(c[i]){
      for(int j = t + 1, val = c[i]; j > 0; --j){
        dp[j] = (dp[j] + val * dp[j - 1]) % MOD;
      }
    }
  }

  ll invFact = 1;
  for(int i = 2; i <= n; ++i){
    invFact = (i * invFact) % MOD;
  }
  invFact = ModularInverse(invFact);

  ll ans = 0;
  for(int i = n; i > 1; --i){
    ans = (ans + invFact * s[i]) % MOD;
    invFact = (invFact * (n - i + 1)) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}