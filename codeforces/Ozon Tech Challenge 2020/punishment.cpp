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
#define MAX_ITER 30

ll a[N];
vector<ll> primes;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void CollectPrimeFactors(ll x){
  if(x <= 0){
    return;
  }

  for(ll p = 2; p * p <= x; ++p){
    if(x % p != 0){
      continue;
    }
    while(x % p == 0){
      x /= p;
    }
    primes.push_back(p);
  }

  if(x > 1){
    primes.push_back(x);
  }
}

ll Compute(int n, ll p){
  ll ans = 0;
  for(int i = 1; i <= n && ans <= n; ++i){
    if(a[i] < p){
      ans += (p - a[i]);
    }
    else{
      ll ansx = a[i] % p;
      ans += min(ansx, p - ansx);
    }
  }
  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  for(int iter = 0; iter < MAX_ITER; ++iter){
    int i = uniform_int_distribution<int>(1, n)(rng);
    CollectPrimeFactors(a[i]);
    CollectPrimeFactors(a[i] - 1);
    CollectPrimeFactors(a[i] + 1);
  }

  sort(primes.begin(), primes.end());
  primes.erase(unique(primes.begin(), primes.end()), primes.end());

  ll ans = n;
  for(ll p : primes){
    ans = min(ans, Compute(n, p));
  }

  printf("%lld\n", ans);

  return 0;
}