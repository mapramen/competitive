#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> base;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

const double PI = 4 * atan(1);

int N;
vector< base > omega;

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

void PolynomialMultiplication(vector<ll>& a, vector<ll>& b, vector<ll>& c){
  int p = a.size() + b.size();
  vector< base > fa(a.begin(), a.end()), fb(b.begin(), b.end());

  FFT(fa, p);
  FFT(fb, p);

  for(int i = 0; i < fa.size(); i++){
    fa[i] = conj(fa[i] * fb[i]);
  }

  FFT(fa, p);

  c.resize(p);
  for(int i = 0, n = fa.size(); i < p; i++){
    c[i] = (ll)(fa[i].real() / n + 0.5);
  }
}

int main(){
  int n, k;

  scanf("%d%d", &n, &k);

  vector<ll> A(n + 1), ans(n + 1);
  ++A[0];

  for(int i = 0, s = 0, c = 0; i < n; ++i){
    int x;
    scanf("%d", &x);
    s += (x < k);
    c = (x < k) ? 0 : 1 + c;
    ans[0] += c;
    ++A[s];
  }

  vector<ll> B(A), C;
  reverse(B.begin(), B.end());

  InitializeFFT(n + n);
  PolynomialMultiplication(A, B, C);

  for(int i = 1, j = n + 1; i <= n; ++i, ++j)
    ans[i] = C[j];

  for(int i = 0; i <= n; ++i)
    printf("%lld ", ans[i]);
  printf("\n");

	return 0;
}
