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

vector<int> primes;
set<int> divisors;

void FillPrimeDivisors(int n){
  primes.clear();

  for(int p = 2; p * p <= n; ++p){
    if(n % p == 0){
      primes.push_back(p);
      while(n % p == 0){
        n /= p;
      }
    }
  }

  if(n > 1){
    primes.push_back(n);
  }
}

void FillDivisors(int n){
  divisors.clear();
  divisors.insert(n);

  for(int d = 2; d * d <= n; ++d){
    if(n % d == 0){
      divisors.insert(d);
      divisors.insert(n / d);
    }
  }

  for(int p: primes){
    divisors.erase(p);
  }
}

void Solve(){
  int n;
  scanf("%d", &n);

  FillPrimeDivisors(n);
  FillDivisors(n);

  vector<int> a;

  for(int i = 0; i < primes.size(); ++i){
    int j = (i + 1) % primes.size();
    int x = primes[i] * primes[j];

    a.push_back(primes[i]);
    int y = 0;
    for(int d: divisors){
      if(d % x == 0){
        y = d;
        break;
      }
    }

    if(y != 0){
      a.push_back(y);
      divisors.erase(y);
    }
  }

  vector<int> b;
  for(int i = 0; i < a.size(); ++i){
    b.push_back(a[i]);

    if(i % 2 == 1){
      continue;
    }

    int p = a[i];
    vector<int> v;
    
    for(int d: divisors){
      if(d % p == 0){
        b.push_back(d);
        v.push_back(d);
      }
    }

    for(int d: v){
      divisors.erase(d);
    }

    v.clear();
  }
  
  int ans = a.size() % 2;
  a.clear();

  for(int d: b){
    printf("%d ", d);
  }
  printf("\n%d\n", ans);

  b.clear();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}