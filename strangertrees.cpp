#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 1000000007

int ModExp(int a, int n){
  ll x = a, y = 1;
  while(n){
    if(n % 2)
      y = (y * x) % MOD;
    x = (x * x) % MOD;
    n /= 2;
  }
  return (int)y;
}

int ModInv(int a){
  return ModExp(a, MOD - 2);
}

void GaussElimination(vector< vector<int> >& A, bool doGaussJordan){
  int n = A.size(), m = A[0].size();
  for(int i = 0; i < n; ++i){
    int j;
    for(j = i; j < n && A[j][i] == 0; ++j);

    if(j == n)
      break;

    if(j != i){
      swap(A[i], A[j]);
      for(j = 0; j < m; ++j)
        A[i][j] = (MOD - A[i][j]) % MOD;
    }

    for(int j = doGaussJordan ? 0 : i + 1, a = ModInv(A[i][i]); j < n; ++j){
      if(j == i || A[j][i] == 0)
        continue;
      int c = (1ll * a * A[j][i]) % MOD;
      for(int k = i; k < m; ++k)
        A[j][k] = (MOD + A[j][k] - (1ll * c * A[i][k]) % MOD) % MOD;
    }
  }
}

int main(){
  int n;
  vector< vector<int> > A, B, C;

  cin >> n;

  A.resize(n);
  B.resize(n);
  C.resize(n);

  for(int i = 0; i < n; ++i){
    A[i].resize(n);
    B[i].resize(n + 1);
    C[i].resize(n);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    cin >> i >> j;
    --i, --j;
    C[i][j] = -1;
    C[j][i] = -1;
    ++C[i][i], ++C[j][j];
  }

  for(int x = 0; x < n; ++x){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        if(i == j)
          A[i][j] = n - 1;
        else
          A[i][j] = -1;
        A[i][j] += x * C[i][j];
      }
    }

    GaussElimination(A, 0);

    int d = 1;
    for(int i = 0; i < n - 1; ++i)
      d = (1ll * d * A[i][i]) % MOD;

    B[x][0] = 1;
    for(int i = 1; i < n; ++i)
      B[x][i] = (1ll * (x + 1) * B[x][i - 1]) % MOD;
    B[x][n] = d;
  }

  GaussElimination(B, 1);

  for(int i = 0; i < n; ++i)
    cout << (1ll * B[i][n] * ModInv(B[i][i])) % MOD << ' ';
  cout << '\n';

  return 0;
}
