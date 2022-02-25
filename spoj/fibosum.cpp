#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

vector<vector<int>> Multiply(vector<vector<int>>& A, vector<vector<int>>& B){
  vector<vector<int>> C(2, vector<int>(2));

  for(int i = 0; i < 2; ++i){
    for(int j = 0; j < 2; ++j){
      int ans = 0;
      for(int k = 0; k < 2; ++k){
        ans = (ans + 1ll * A[i][k] * B[k][j]) % MOD;
      }
      C[i][j] = ans;
    }
  }

  return C;
}

int Fib(int n){
  vector<vector<int>> A{{1, 1}, {1, 0}};
  vector<vector<int>> B{{1, 0}, {0, 1}};

  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      B = Multiply(B, A);
    }
    A = Multiply(A, A);
  }

  return B[0][1];
}

int FibSum(int n){
  return n <= 0 ? 0 : (MOD + Fib(n + 2) - 1) % MOD;
}

int FibSum(int l, int r){
  return (MOD + FibSum(r) - FibSum(l - 1)) % MOD;
}

int Solve(){
  int l, r;
  scanf("%d%d", &l, &r);
  return FibSum(l, r);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}