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
#define N 11
#define MOD 1000003

ll a[N][N + 1];

ll ModExp(ll a, ll n){
  ll y = 1;
  for( ; n; n /= 2){
    if(n % 2){
      y = (y * a) % MOD;
    }
    a = (a * a) % MOD;
  }
  return y;
}

ll ModInv(ll a){
  return ModExp(a, MOD - 2ll);
}

void PrintStatement(char c, int x){
  printf("%c %d\n", c, x);
  fflush(stdout);
}

int Query(int x){
  PrintStatement('?', x);
  scanf("%d", &x);
  return x;
}

void PrintAns(int x){
  PrintStatement('!', x);
}

int main(){
  for(int i = 0; i < N; ++i){
    a[i][N] = Query(i);
  }

  for(int i = 0; i < N; ++i){
    a[i][0] = 1;
    for(int j = 1, p = i; j < N; ++j){
      a[i][j] = p;
      p = (p * i) % MOD;
    }
  }

  for(int i = 0; i < N; ++i){
    int k;
    for(k = i; a[k][i] == 0; ++k);

    for(int j = 0; j <= N; ++j){
      swap(a[i][j], a[k][j]);
    }

    ll pivotInverse = ModInv(a[i][i]);
    for(int j = i; j <= N; ++j){
      a[i][j] = (pivotInverse * a[i][j]) % MOD;
    }

    for(int k = 0; k < N; ++k){
      if(k == i){
        continue;
      }

      for(int j = N; j >= i; --j){
        a[k][j] = (a[k][j] - a[i][j] * a[k][i]) % MOD;
      }
    }
  }

  vector<ll> p;
  for(int i = N - 1; i > -1; --i){
    p.push_back((MOD + a[i][N]) % MOD);
  }

  for(int i = 0; i < MOD; ++i){
    ll x = 0;
    for(ll b : p){
      x = (i * x + b) % MOD;
    }
    if(x == 0){
      PrintAns(i);
      return 0;
    }
  }

  PrintAns(-1);
  return 0;
}