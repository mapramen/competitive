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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 10001
#define MOD 998244353

ll fact[N], invFact[N];

ll ModularExponentation(ll a, ll n){
  ll ans = 1;
  for( ; n; n /= 2){
    if(n % 2){
      ans = (ans * a) % MOD;
    }
    a = (a * a) % MOD;
  }
  return ans;
}

ll ModInv(ll a){
  return ModularExponentation(a, MOD - 2);
}

void Initialise(){
  fact[0] = 1;
  for(int i = 1; i < N; ++i){
    fact[i] = (i * fact[i - 1]) % MOD;
  }

  invFact[N - 1] = ModInv(fact[N - 1]);
  for(int i = N - 2; i > -1; --i){
    invFact[i] = ((i + 1) * invFact[i + 1]) % MOD;
  }
}

ll C(int n, int r){
  if(n < 0 || r < 0 || n < r){
    return 0ll;
  }

  ll p = fact[n];
  ll q = (invFact[r] * invFact[n - r]) % MOD;
  
  return (p * q) % MOD;
}

ll Beggar(int n, int m){
  if(n == 0 && m == 0){
    return 1ll;
  }
  ll ans = C(n + m - 1, n);
  return ans;
}

ll BeggarWithUpperConstraint(int n, int m, int k){
  ll ans = 0;
  for(int i = 0, sgn = 1; i <= m; ++i, sgn = -sgn){
    ans = (ans + sgn * C(m, i) * Beggar(n - i * (k + 1), m)) % MOD;
  }
  ans = (MOD + ans) % MOD;
  return ans;
}

int main(){
  int n, m, k;

  cin >> m >> n >> k;

  Initialise();

  ll ans = 0;
  for(int i = k; i <= n; ++i){
    for(int j = 1; j <= m && i * j <= n; ++j){
      ll ansx = (C(m, j) * BeggarWithUpperConstraint(n - i * j, m - j, i - 1)) % MOD;
      ans = (ans + ansx) % MOD;
    }
  }

  ans = (ans * ModInv(1ll * m)) % MOD;
  ans = (ans * ModInv(Beggar(n - k, m))) % MOD;

  cout << ans << '\n';

  return 0;
}