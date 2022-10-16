#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 998244353
#define ROOT 15311432
#define ROOT_INV 469870224
#define ROOT_PW (1 << 23)

//-------------------------------------- NTT starts --------------------------------------//

ll ModularExponentation(ll a, ll n){
  ll ans = 1;

  for( ; n > 0; n /= 2){
    if(n % 2)
    ans = (ans * a) % MOD;
    a = (a * a) % MOD;
  }

  return ans;
}

ll ModularInverse(int a){
  return ModularExponentation(a, MOD - 2);
}

void FFT(vector<int>& a, bool invert) {
  int n = a.size();

  for(int i = 1, j = 0; i < n; ++i){
    int bit = n >> 1;
    for( ; j & bit; bit >>= 1){
      j ^= bit;
    }
    j ^= bit;

    if(i < j){
      swap(a[i], a[j]);
    }
  }

  for(int len = 2; len <= n; len <<= 1){
    int wlen = invert ? ROOT_INV : ROOT;
    for(int i = len; i < ROOT_PW; i <<= 1){
      wlen = (int)(1LL * wlen * wlen % MOD);
    }

    for(int i = 0; i < n; i += len){
      int w = 1;
      for(int j = 0; j < len / 2; ++j){
        int u = a[i + j], v = (int)(1LL * a[i + j + len/2] * w % MOD);
        a[i + j] = u + v < MOD ? u + v : u + v - MOD;
        a[i + j + len/2] = u - v >= 0 ? u - v : u - v + MOD;
        w = (int)(1LL * w * wlen % MOD);
      }
    }
  }

  if(invert){
    int n_1 = ModularInverse(n);
    for(int& x: a){
      x = (int)(1LL * x * n_1 % MOD);
    }
  }
}

vector<int> MultiplyPolynomials(vector<int>&a, vector<int>& b){
  int n = 1;
  for(int m = a.size() + b.size(); n < m; n <<= 1);

  a.resize(n), b.resize(n);
  FFT(a, false), FFT(b, false);

  vector<int> c(n);
  for(int i = 0; i < n; ++i){
    c[i] = (1ll * a[i] * b[i]) % MOD;
  }
  FFT(c, true);

  a.clear(), b.clear();

  return c;
}

void Squared(vector<int>& a){
  int n = a.size();

  FFT(a, false);
  for(int i = 0; i < n; ++i){
    a[i] = (1ll * a[i] * a[i]) % MOD;
  }
  FFT(a, true);
}
//-------------------------------------- NTT ends --------------------------------------//

vector<int> Initialize(int k){
  int n = 1;
  for( ; n <= k; n *= 2);
  n *= 2;

  vector<int> dp(n);
  for(int i = 0; i <= k; ++i){
    dp[i] = 1;
  }

  return dp;
}

int main(){
  int n, k, f;
  scanf("%d%d%d", &n, &k, &f);

  vector<int> dp = Initialize(k);
  Squared(dp);

  while(--n){
    for(int i = 2 * k, s = 0; i != -1; --i){
      s = (s + dp[i]) % MOD;
      dp[i] = (1ll * (k - i) * dp[i] + s) % MOD;
    }
    fill(dp.begin() + k + 1, dp.end(), 0);
    Squared(dp);
  }

  printf("%d\n", 2 * k < f ? 0 : dp[f]);

  return 0;
}