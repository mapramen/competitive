#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 1000000007

string s;

vector< vector<ll> > GetMatrix(string t){
  int n = s.size();
  vector< vector<ll> > A(n + 1, vector<ll>(n + 1, 0));

  for(int i = 0; i <= n; ++i)
    A[i][i] = 1 + (i == 0) + (i == n);

  for(int i = 0; i <= n; ++i){
    string x = string(s, 0, i) + t;
    string y = string(s, 0, i + 1);
    if(x.compare(y) != 0)
      continue;
    A[i + 1][i] += 1;
  }

  return A;
}

void MatrixMultiplication(vector< vector<ll> >& A, vector< vector<ll> >& B, vector< vector<ll> >& C){
  for(int i = 0, n = A.size(); i < n; ++i){
    for(int j = 0; j < n; ++j){
      ll val = 0;
      for(int k = 0; k < n; ++k){
        if(A[i][k] == 0 || B[k][j] == 0)
          continue;
        val = (val + A[i][k] * B[k][j]) % MOD;
      }
      C[i][j] = val;
    }
  }
}

int main(){
  int n, k;

  cin >> n >> k >> s;
  reverse(s.begin(), s.end());

  vector< vector<ll> > A = GetMatrix("0"), B = GetMatrix("1"), C(n + 1, vector<ll>(n + 1, 0));

  if(k == 0)
    swap(A, B);
  else{
    for(int i = 2; i <= k; ++i){
      MatrixMultiplication(B, A, C);
      swap(A, B);
      swap(B, C);
    }
  }

  cout << B[n][0] << '\n';

  return 0;
}
