#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> base;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MAXN 125001
#define M 6

const double PI = 4 * atan(1);

int N;
vector< base > omega;

void InitializeFFT(int n){
  for(n++, N = 1; N < n; N <<= 1);
  N <<= 1;
  omega.resize(N);
  double thetax = 2 * PI / N, theta = 0;
  for(int i = 0; i < N; i++, theta += thetax)
  omega[i] = base(cos(theta), sin(theta));
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
    if(i < j)
    swap(a[i], a[j]);
  }
  //BitReverseCopy ends

  for(int l = 2; l <= n; l <<= 1){
    for(int i = 0, F = N / l; i < n; i += l){
      for(int j = 0, f = 0; j < (l >> 1); j++, f += F){
        int x = i + j, y = x + (l >> 1);
        base t = omega[f] * a[y], u = a[x];
        a[x] = u + t, a[y] = u - t;
      }
    }
  }
}

int A[MAXN], B[MAXN], p[MAXN][M], ans[MAXN];

int Find(int k, int i){
  return p[k][i] == i ? i : p[k][i] = Find(k, p[k][i]);
}

void Union(int k, int i, int j){
  i = Find(k, i), j = Find(k, j);
  if(i == j)
    return ;
  if(i > j)
    swap(i, j);
  p[k][j] = i;
  ++ans[k];
}

int ReadString(int A[]){
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); ++i)
    A[i + 1] = s[i] - 'a';
  return (int)s.size();
}

void FillVector(int A[], vector<int>& a, int x){
  a[0] = 0;
  for(int i = 1, n = a.size(); i < n; ++i)
    a[i] = (A[i] == x);
}

void FillVectors(int n, int A[], vector< vector< base > >& fa, bool doReverse = 0){
  vector<int> a(n + 1);
  for(int x = 0; x < M; ++x){
    FillVector(A, a, x);
    if(doReverse)
      reverse(a.begin(), a.end());
    vector< base > f(a.begin(), a.end());
    FFT(f, N);
    fa.PB(f);
  }
}

int main(){
  int n = ReadString(A), m = ReadString(B);

  InitializeFFT(MAXN);

  for(int k = 1; k <= n; ++k)
    for(int i = 0; i < M; ++i)
      p[k][i] = i;

  vector< vector< base > > fa, fb;

  FillVectors(n, A, fa, 0);
  FillVectors(m, B, fb, 1);

  vector< base > fc(N);
  vector<int> c(N);

  for(int x = 0; x < M; ++x){
    for(int y = 0; y < M; ++y){
      if(x == y)
        continue;

      for(int i = 0; i < N; i++)
        fc[i] = conj(fa[x][i] * fb[y][i]);

      FFT(fc, N);

      for(int i = 0, n = fc.size(); i < N; i++)
        c[i] = (int)(fc[i].real() / n + 0.5);

      for(int i = 0; i < N; ++i){
        if(c[i] == 0)
          continue;

        int k = i - m + 1;
        if(k > 0 && k <= n - m + 1){
          Union(k, x, y);
        }
      }
    }
  }

  for(int i = 1; i <= n - m + 1; ++i)
    printf("%d ", ans[i]);
  printf("\n");

  return 0;
}
