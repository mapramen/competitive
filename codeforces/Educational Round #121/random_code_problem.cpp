#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M 720720
#define MOD 998244353

int dpm[M], dpc[M];

pii ReadInput(){
  int n, a, x, y, k, mod;
  cin >> n >> a >> x >> y >> k >> mod;

  for(int i = 0; i < n; ++i){
    int m = a / M, r = a % M;
    dpm[r] = (dpm[r] + 1ll * m * M) % MOD;
    ++dpc[r];
    a = (1ll * a * x + y) % mod;
  }

  return {n, k};
}

int Calculate(int n, int k){
  int ans = 0;
  
  for(int r = 0; r < M; ++r){
    int m = dpm[r], c = dpc[r];
    if(m == 0 && c == 0){
      continue;
    }
    
    dpm[r] = 0, dpc[r] = 0;

    ans = (ans + m + 1ll * c * r) % MOD;

    int nr = r - (r % k);
    dpm[r] = (1ll * (n - 1) * m) % MOD;
    dpc[r] = (1ll * (n - 1) * c) % MOD;
    
    dpm[nr] = (dpm[nr] + m) % MOD;
    dpc[nr] = (dpc[nr] + c) % MOD;
  }

  return ans;
}

int main(){
  int n, k;
  tie(n, k) = ReadInput();

  ll ans = 0;
  for(int kx = 1; kx <= k; ++kx){
    ans = (n * ans + Calculate(n, kx)) % MOD;
  }

  cout << ans << '\n';

  return 0;
}