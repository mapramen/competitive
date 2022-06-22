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

vector<int> GetCount(string& s, string& t, char ch){
  int n = s.size(), m = t.size();
  
  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    a[i] = s[i] == ch;
  }

  vector<int> b(m);
  for(int j = m - 1, i = 0; i < m; ++i, --j){
    b[j] = t[i] == ch;
  }

  vector<int> c;
  PolynomialMultiplication(a, b, c);

  return vector<int>(c.begin() + m - 1, c.begin() + n);
}

int main(){
  string s, t;
  cin >> s >> t;

  int n = s.size();
  InitializeFFT(n);

  vector<char> dna_chars {'A', 'C', 'G', 'T'};

  vector<int> cnt(s.size() - t.size() + 1);
  for(char c: dna_chars){
    vector<int> cntx = GetCount(s, t, c);
    for(int i = cnt.size() - 1; i != -1; --i){
      cnt[i] += cntx[i];
    }
  }

  int ans = t.size() - *max_element(cnt.begin(), cnt.end());

  printf("%d\n", ans);

  return 0;
}