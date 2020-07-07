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
#define tiii tuple<int,int,int>
#define B 3
#define K 11
#define N 1771561
#define M (B * (B - 1))
#define MOD 1000000007

int fact[N], invFact[N], dp[B][N], u[M], v[M];
vector<tiii> moves[B];
int movesJ[B][B], movesK[B][B], movesX[B][B];

inline void ModuloAdd(int &a, int &val){
  if(val == 0){
    return;
  }

  a += val;
  if(a > MOD){
    a -= MOD;
  }
}

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

int Beggar(int n, int m){
  return nCr(n + m - 1, m - 1);
}

int FillVector(int x){
  int l = 1;
  for(int i = 0; i < M; ++i, x /= K){
    u[i] = x % K;
    if(u[i] > v[i]){
      return -1;
    }
    l += u[i];
  }
  return l;
}

void PreProcess(){
  Initialise();

  for(int i = 0, k = 0, x = 1; i < B; ++i){
    for(int j = 0; j < B; ++j){
      if(j == i){
        continue;
      }
      moves[i].push_back({j, k, x});
      ++k, x *= K;
    }
  }

  for(int i = 0; i < B; ++i){
    for(int f = 0; f < 2; ++f){
      tie(movesJ[i][f], movesK[i][f], movesX[i][f]) = moves[i][f];
    }
  }

  for(int i = 0; i < B; ++i){
    dp[i][0] = 1;
  }
}

int main(){
  int n;

  cin >> n;

  for(int i = 0; i < M; ++i){
    cin >> v[i];
  }

  PreProcess();

  int ans = 3;
  for(int mask = 1; mask < N; ++mask){
    int l = FillVector(mask);

    if(l == -1){
      continue;
    }

    int ansy = 0;
    for(int i = 0; i < B; ++i){
      int ansx = 0;
      for(int f = 0; f < 2; ++f){
        if(u[movesK[i][f]] == 0){
          continue;
        }
        ModuloAdd(ansx, dp[movesJ[i][f]][mask - movesX[i][f]]);
      }

      if(ansx){
        dp[i][mask] = ansx;
        ModuloAdd(ansy, ansx);
      }
    }

    ans = (ans + 1ll * ansy * Beggar(n - l, l)) % MOD;
  }

  cout << ans << '\n';

  return 0;
}