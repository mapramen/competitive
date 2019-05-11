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
#define N 100001
#define MOD 1000000007

vector< vector<int> > divisors(N);
int c[N], dp[N];

int ModularExponentation(int a, int n){
  ll x = a, y = 1;
  for( ; n; n /= 2){
    if(n % 2){
      y = (y * x) % MOD;
    }
    x = (x * x) % MOD;
  }
  return y;
}

int ModularInverse(int a){
  return ModularExponentation(a, MOD - 2);
}

int main(){
  int n;
  cin >> n;

  for(int i = 1; i <= n; ++i){
    for(int j = i; j <= n; j += i){
      divisors[j].push_back(i);
    }
    reverse(divisors[i].begin(), divisors[i].end());
  }

  int ans = 0;
  for(int i = 2; i <= n; ++i){
    int &val = dp[i];
    val = n;
    
    for(int j : divisors[i]){
      c[j] = (n / j);
    }

    for(int x = 0; x < divisors[i].size(); ++x){
      for(int y = x + 1; y < divisors[i].size(); ++y){
        if(divisors[i][x] % divisors[i][y] == 0){
          c[divisors[i][y]] -= c[divisors[i][x]];
        }
      }
    }

    for(int j : divisors[i]){
      if(j == 1 || j == i){
        continue;
      }
      val = (val + 1ll * c[j] * dp[j]) % MOD;
    }

    val = (1ll * val * ModularInverse(n - c[i])) % MOD;
    ans = (ans + val) % MOD;

    // printf("i = %d c[i] = %d val = %d\n", i, c[i], val);
  }

  ans = (1 + 1ll * ModularInverse(n) * ans) % MOD;

  printf("%d\n", ans);

  return 0;
}