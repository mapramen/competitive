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
#define MOD 998244353
#define PROOT 3
#define N (1 << 21)

int N_INV;
vector<int> swapIndex(N);
vector<int> omega(N), omega_inv(N), A(N);
ll ROOT, ROOT_INV;

ll ModularExponentation(ll a, ll n){
  ll ans = 1;

  for( ; n > 0; n /= 2){
    if(n % 2)
    ans = (ans * a) % MOD;
    a = (a * a) % MOD;
  }

  return ans;
}

void InitializeFFT(){
  ROOT = ModularExponentation(1ll * PROOT, (MOD - 1) / N);
  omega[0] = omega_inv[0] = 1;
  ROOT_INV = ModularExponentation(ROOT, MOD - 2);
  N_INV = ModularExponentation(N, MOD - 2);

  for(int i = 1; i < N; i++){
    omega[i] = (1ll * ROOT * omega[i - 1]) % MOD;
    omega_inv[i] = (1ll * ROOT_INV * omega_inv[i - 1]) % MOD;
  }

  for(int i = 0; i < N; i++){
    int j = 0, k = i;
    for(int x = 1; x < N; x <<= 1){
      j = (j << 1) | (k & 1);
      k >>= 1;
    }
    swapIndex[i] = j;
  }
}

void FFT(vector<int>& a, int isInv = 0){
  for(int i = 0; i < N; i++){
    if(swapIndex[i] < i)
      swap(a[i], a[swapIndex[i]]);
  }

  for(int l = 2; l <= N;l <<= 1){
    for(int i = 0, F = N / l; i < N; i += l){
      for(int j = 0, f = 0; j < (l >> 1); j++, f += F){
        int x = i + j, y = x + (l >> 1);
        int t = (1ll * (isInv * omega_inv[f] + (1 - isInv) * omega[f]) * a[y]) % MOD, u = a[x];
        a[x] = (u + t) % MOD, a[y] = (MOD + u - t) % MOD;
      }
    }
  }

  if(isInv){
    for(int i = 0; i < N; ++i){
      a[i] = (1ll * N_INV * a[i]) % MOD;
    }
  }
}

int main(){
  int n, m;

  cin >> n >> m;

  while(m--){
    int i;
    cin >> i;
    A[i] = 1;
  }

  InitializeFFT();
  FFT(A);
  n /= 2;

  for(int i = 0; i < N; ++i){
    A[i] = ModularExponentation(A[i], n);
  }

  FFT(A, 1);

  ll ans = 0;
  for(int i = 0; i < N; ++i){
    ll x = A[i];
    ans += ((x * x) % MOD);
  }

  ans %= MOD;

  cout << ans << '\n';

  return 0;
}