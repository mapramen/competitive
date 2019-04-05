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
#define N 1000001
#define MOD 1000000007

ll fact[N], invFact[N], p[N];

ll ModularExponentation(ll a, ll n){
  ll ans = 1 % MOD;
  for( ; n; n /= 2, a = (a * a) % MOD){
    if(n % 2){
      ans = (ans * a) % MOD;
    }
  }
  return ans;
}

ll ModularInverse(ll a){
  return ModularExponentation(a, MOD - 2);
}

void Initialise(ll n, ll m){
  int x = (n * m) % MOD;
  fact[0] = 1;
  p[0] = 1;
  for(int i = 1; i < N; ++i){
    fact[i] = (i * fact[i - 1]) % MOD;
    p[i] = (x * p[i - 1]) % MOD;
  }

  invFact[N - 1] = ModularInverse(fact[N - 1]);
  for(int i = N - 2; i > -1; --i){
    invFact[i] = ((i + 1) * invFact[i + 1]) % MOD;
  }
}

int main(){
  ll n, m;

  cin >> n >> m;

  Initialise(n, m);

  ll ans = 0;
  for(int k = 2; k <= min(n, m + 1); ++k){
    ll ansx = (k * p[n - k]) % MOD;
    ansx = (ansx * invFact[n - k]) % MOD;
    ansx = (ansx * invFact[m - k + 1]) % MOD;
    ansx = (ansx * invFact[k - 2]) % MOD;
    ans = (ans + ansx) % MOD;
  }

  ans = (ans * fact[n - 2]) % MOD;
  ans = (ans * fact[m - 1]) % MOD;
  ans = (ans * ModularInverse(n)) % MOD;

  cout << ans << '\n';

  return 0;
}