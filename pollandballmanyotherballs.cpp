#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> base;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define K (1 << 15)
#define MOD 998244353
#define PROOT 3
#define B 2

int N = K << 1, N_INV;
vector<int> swapIndex(N);
vector<int> omega(N), omega_inv(N), a[B][B], b[B][B], new_a[B][B], new_b[B][B];
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

void InitializeData(){
  for(int i = 0; i < B; i++)
    for(int j = 0; j < B; j++)
      a[i][j].resize(N), b[i][j].resize(N), new_a[i][j].resize(N), new_b[i][j].resize(N);

  a[0][0][0] = a[0][0][1] = a[0][1][1] = a[1][0][0] = 1;
  b[0][0][0] = b[0][0][1] = b[1][0][0] = 1;
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
}

void FFTMatrix(vector<int> a[B][B]){
  for(int i = 0; i < B; i++)
    for(int j = 0; j < B; j++)
      FFT(a[i][j], 0);
}

void MultiplyFFTMatrix(vector<int> a[B][B], vector<int> b[B][B], vector<int> c[B][B]){
  for(int i = 0; i < B; i++){
    for(int j = 0; j < B; j++){
      for(int x = 0; x < N; x++)
        c[i][j][x] = 0;

      for(int k = 0; k < B; k++)
        for(int x = 0; x < N; x++)
          c[i][j][x] = (c[i][j][x] + (int)((1ll * a[i][k][x] * b[k][j][x]) % MOD)) % MOD;

      FFT(c[i][j], 1);

      for(int x = 0; x < K; x++)
        c[i][j][x] = (1ll * N_INV * c[i][j][x]) % MOD;

      for(int x = K; x < N; x++)
        c[i][j][x] = 0;
    }
  }
}

void CopyMatrix(vector<int> s[B][B], vector<int> t[B][B]){
  for(int i = 0; i < B; i++)
    for(int j = 0; j < B; j++){
      for(int x = 0; x < N; x++)
        t[i][j][x] = s[i][j][x];
    }
}

int main(){
  int n, m;

  cin >> n >> m;

  InitializeFFT();
  InitializeData();

  for(n--; n > 0; n /= 2){
    FFTMatrix(a);

    if(n % 2){
      FFTMatrix(b);
      MultiplyFFTMatrix(a, b, new_b);
      CopyMatrix(new_b, b);
    }

    MultiplyFFTMatrix(a, a, new_a);
    CopyMatrix(new_a, a);
  }

  for(int i = 1; i <= m; i++)
    printf("%d ", b[0][0][i]);
  printf("\n");

  return 0;
}
