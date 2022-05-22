#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> base;

#define pii pair<int,int>
#define pll pair<ll,ll>

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

void PolynomialMultiplication(vector<int>& a, vector<int>& b, vector<int>& c){
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
    c[i] = (ll)(fa[i].real() / n + 0.5);
  }
}

vector<int> GetCount(string s, char ch){
  int n = s.size();
  
  vector<int> a(n), b(n);
  for(int i = 0, j = n - 1; i < n; ++i, --j){
    if(s[i] != ch){
      continue;
    }
    a[i] = 1, b[j] = 1;
  }

  vector<int> c;
  PolynomialMultiplication(a, b, c);

  c.resize(n);
  reverse(c.begin(), c.end());

  return c;
}

int main(){
  string s;
  cin >> s;

  int n = s.size();
  InitializeFFT(n);

  vector<int> cnt(n + 1);
  for(char c = 'a'; c <= 'c'; ++c){
    vector<int> cntx = GetCount(s, c);
    for(int i = 0; i < n; ++i){
      cnt[i] += cntx[i];
    }
  }

  int ans = *max_element(cnt.begin() + 1, cnt.end());

  printf("%d\n", ans);
  for(int i = 0; i < n; ++i){
    if(cnt[i] == ans){
      printf("%d\n", i);
    }
  }

  return 0;
}