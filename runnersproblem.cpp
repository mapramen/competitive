#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define M 3
#define R 1
#define N 10001
#define MOD 1000000007

int T[2 * N][M], t[N];
ll l[N], r[N], A[M][M], B[M][M], temp[M][M];
vector<ll> v;

void PreProcess(int n, ll m){
  for(int i = 1; i <= n; ++i)
    v.PB(l[i]), v.PB(r[i]);
  v.PB(2);
  v.PB(m + 1);

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for(int i = 1; i <= n; ++i){
    l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
    r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
    ++T[l[i]][t[i]];
    --T[r[i]][t[i]];
  }

  for(int i = 1; i < v.size(); ++i)
    for(int j = 0; j < M; ++j)
      T[i][j] += T[i - 1][j];

  B[1][1] = 1;
}

void FillBaseMatrix(ll A[M][M], int T[M]){
  for(int i = 0; i < M; ++i)
    for(int j = 0; j < M; ++j)
      A[i][j] = (T[i] == 0 && abs(i - j) <= R);
}

void MatrixMultiplication(ll A[M][M], ll B[M][M], ll C[M][M]){
  for(int i = 0; i < M; ++i){
    for(int j = 0; j < M; ++j){
      temp[i][j] = 0;
      for(int k = 0; k < M; ++k)
        temp[i][j] = (temp[i][j] + A[i][k] * B[k][j]) % MOD;
    }
  }

  for(int i = 0; i < M; ++i)
    for(int j = 0; j < M; ++j)
      C[i][j] = temp[i][j];
}

void MatrixExponentation(ll n, ll A[M][M], ll B[M][M]){
  while(n){
    if(n % 2)
      MatrixMultiplication(A, B, B);
    MatrixMultiplication(A, A, A);
    n /= 2;
  }
}

int main(){
  int n;
  ll m;

  scanf("%d%lld", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d%lld%lld", &t[i], &l[i], &r[i]);
    ++r[i];
    --t[i];
  }

  PreProcess(n, m);

  for(int i = 0; i < v.size() - 1; ++i){
    FillBaseMatrix(A, T[i]);
    MatrixExponentation(v[i + 1] - v[i], A, B);
  }

  printf("%lld\n", B[1][1]);

  return 0;
}
