#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> base;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define LOGN 13

const double PI = 4 * atan(1);

int N;
vector<base> omega;

void InitializeFFT(int n){
  for(n++, N = 1; N < n; N <<= 1);
  N <<= 1;

  omega.resize(N);

  double thetax = 2 * PI / N, theta = 0;
  for(int i = 0; i < N; i++, theta += thetax){
    omega[i] = base(cos(theta), sin(theta));
  }
}

void FFT(vector<base>& a, int l){
  int n;
  for(n = 1; n < l; n <<= 1);
  a.resize(n);

  //BitReverseCopy
  for(int i = 0; i < n; i++){
    int j = 0, k = i;
    for(int x = 1; x < n; x <<= 1){
      j = (j << 1) | (k & 1);
      k >>= 1;
    }
    if(i < j){
      swap(a[i], a[j]);
    }
  }
  //BitReverseCopy ends

  for(int l = 2; l <= n;l <<= 1){
    for(int i = 0, F = N / l; i < n; i += l){
      for(int j = 0, f = 0; j < (l >> 1); j++, f += F){
        int x = i + j, y = x + (l >> 1);
        base t = omega[f] * a[y], u = a[x];
        a[x] = u + t, a[y] = u - t;
      }
    }
  }
}

void PolynomialMultiplication(vector<double>& a, vector<double>& b, vector<double>& c){
  int p = a.size() + b.size();
  vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());

  FFT(fa, p);
  FFT(fb, p);

  for(int i = 0; i < fa.size(); i++){
    fa[i] = conj(fa[i] * fb[i]);
  }

  FFT(fa, p);

  c.resize(p);
  for(int i = 0, n = fa.size(); i < p; i++){
    c[i] = fa[i].real() / n;
  }
}

vector<vector<double>> A(LOGN);

void Initialize(){
  InitializeFFT(1E5);
  
  A[0] = vector<double>(7, 1.0 / 6);
  A[0][0] = 0;

  for(int k = 1; k < LOGN; ++k){
    PolynomialMultiplication(A[k - 1], A[k - 1], A[k]);
  }
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  if(n >= (1 << LOGN) || 6 * n < m){
    return 0;
  }

  vector<double> dp(1, 1.0);
  for(int k = 0; k < LOGN; ++k){
    if((n & (1 << k)) != 0){
      PolynomialMultiplication(A[k], dp, dp);
    }
  }

  return (int)(100 * dp[m]);
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}