#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001
#define MOD 1000000007

int a[N], c[N], f[N];

void Initialise(){
  for(int i = 1; i < N; ++i){
    a[i] = i, c[i] = 1, f[i] = 1;
  }

  for(int i = 2; i < N; ++i){
    for(int j = i; j < N; j += i){
      int x = 1;
      while(a[j] % i == 0){
        x *= i, a[j] /= i;
      }
      f[j] = (1ll * f[j] * (max(c[i], x) / c[i])) % MOD;
      c[i] = max(c[i], x);
    }
  }

  for(int i = 2; i < N; ++i){
    f[i] = (1ll * f[i] * f[i - 1]) % MOD;
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return f[n];
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}