#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

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

vector<vector<int>> Fib(ll n){
  vector<vector<int>> A{{1, 1}, {1, 0}};
  vector<vector<int>> B{{1, 0}, {0, 1}};

  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      B = MatrixMultiplication(B, A);
    }
    A = MatrixMultiplication(A, A);
  }

  return B;
}

int Solve(){
  ll n;
  scanf("%lld", &n);
  if(n == 0){
    return 0;
  }

  vector<vector<int>> B = Fib(2 * n + 1);
  return (1ll * B[0][1] * B[1][1]) % MOD;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}