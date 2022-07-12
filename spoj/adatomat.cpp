#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 20000001
#define M 50001
#define MOD 1000000007

int A[N], B[N], C[M];

int Solve(){
  int n, a, b;
  ll x;
  scanf("%d%d%d%lld", &n, &a, &b, &x);

  A[1] = x;
  for(int i = 2; i <= n; ++i){
    x = (a * x + b) % MOD;
    A[i] = x;
  }

  for(int k = 0; k < M; ++k){
    C[k] = 0;
  }

  for(int i = 1; i <= n; ++i){
    ++C[(A[i] % M)];
  }

  for(int k = 1; k < M; ++k){
    C[k] += C[k - 1];
  }

  for(int i = n; i != 0; --i){
    int j = C[(A[i] % M)]--;
    B[j] = A[i];
  }

  for(int k = 0; k < M; ++k){
    C[k] = 0;
  }

  for(int i = 1; i <= n; ++i){
    ++C[(B[i] / M)];
  }

  for(int k = 1; k < M; ++k){
    C[k] += C[k - 1];
  }

  int ans = 0;
  for(int i = n; i != 0; --i){
    int j = C[(B[i] / M)]--;
    ans = (ans + 1ll * j * B[i]) % MOD;
  }
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}