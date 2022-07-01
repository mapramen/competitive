#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 98765431

vector<vector<int>> MatrixMultiplication(vector<vector<int>>& A, vector<vector<int>>& B){
  int n = A.size();

  vector<vector<int>> C(n, vector<int>(n));
  
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      int ans = 0;
      for(int k = 0; k < n; ++k){
        ans = (ans + 1ll * A[i][k] * B[k][j]) % MOD;
      }
      C[i][j] = ans;
    }
  }

  return C;
}

pii Coeff(int n, int m){
  vector<vector<int>> A{{n - 1, 1}, {0, -1}};
  vector<vector<int>> B{{1, 0}, {0, 1}};

  for( ; m > 0; m /= 2){
    if(m % 2 == 1){
      B = MatrixMultiplication(B, A);
    }
    A = MatrixMultiplication(A, A);
  }

  return {B[0][1], B[1][1]};
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  int s = 0;
  for(int x: a){
    s = (s + x) % MOD;
  }

  int A, B;
  tie(A, B) = Coeff(n, m);

  for(int x: a){
    printf("%lld\n", (1ll * A * s + 1ll * B * x) % MOD);
  }

  return 0;
}