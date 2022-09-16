#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001
#define MOD 1000000003

int f[N];

void Initialize(){
  for(int i = 1; i < N; ++i){
    f[i] = (1ll * i * i * i) % MOD;
  }

  for(int i = 1; i < N; ++i){
    f[i] = (f[i] + f[i - 1]) % MOD;
  }

  for(int i = 1; i < N; ++i){
    f[i] = (f[i] + f[i - 1]) % MOD;
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return f[n];
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}