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
#define N 100
#define MOD 998244353
#define PROOT 3

ll A[N][N], B[N][N], temp[N][N];
int phi_mod;

int Phi(int n){
  int ans = 1;
  for(int i = 2; i * i <= n; ++i){
    if(n % i != 0){
      continue;
    }
    for( ; n % i == 0; n /= i, ans *= i);
    ans /= n;
    ans *= (i - 1);
  }

  if(n > 1){
    ans *= (n - 1);
  }

  return ans;
}

void MatrixMultiplication(int n, int mod, ll A[N][N], ll B[N][N], ll C[N][N]){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      ll &val = temp[i][j];
      val = 0;
      for(int k = 0; k < n; ++k){
        val = (val + A[i][k] * B[k][j]) % mod;
      }
    }
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      C[i][j] = temp[i][j];
    }
  }
}

int GetPower(int n, int m){
  for(int i = 1; i < n; ++i){
    A[i][i - 1] = 1;
  }

  for(int i = 0; i < n; ++i){
    B[0][0] = 1;
  }

  m -= n;

  for( ; m; m /= 2){
    if(m % 2){
      MatrixMultiplication(n, phi_mod, A, B, B);
    }
    MatrixMultiplication(n, phi_mod, A, A, A);
  }

  return B[0][0];
}

int ModExp(int a, int n, int mod){
  ll x = a, y = 1 % mod;
  for( ; n; n /= 2){
    if(n % 2){
      y = (y * x) % mod;
    }
    x = (x * x) % mod;
  }
  return y;
}

int DiscreteLogarithm(int a, int b, int m){
  int n = sqrt(m + 0.0) + 1;
  int an = ModExp(a, n, m);

  vector< pii > v;
  for(int i = 1, an = ModExp(a, n, m), cur = an; i <= n; ++i, cur = (1ll * cur * an) % m){
    v.push_back(make_pair(cur, i));
    
  }
  sort(v.begin(), v.end());

  for(int i = 0, cur = b; i <= n; ++i, cur = (1ll * cur * a) % m){
    int j = lower_bound(v.begin(), v.end(), make_pair(cur, 0)) - v.begin();
    if(j == v.size() || v[j].first != cur){
      continue;
    }
    return v[j].second * n - i;
  }

  return -1;
}

int main(){
  int n, k, m;

  cin >> n;

  phi_mod = Phi(MOD);

  for(int j = 0; j < n; ++j){
    cin >> A[0][j];
    A[0][j] %= phi_mod;
  }

  cin >> m >> k;

  int y = GetPower(n, m);
  int a = ModExp(PROOT, y, MOD), b = k;
  int x = DiscreteLogarithm(a, b, MOD);

  int ans = x < 0 ? -1 : ModExp(PROOT, x, MOD);

  cout << ans << '\n';

  return 0;
}