#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 250001
#define MOD 998244353
#define ROOT 363395222
#define ROOT_INV 704923114
#define ROOT_PW (1 << 19)

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

vector<vector<int>> adj(N);

vector<int> Solve(int l, int r){
  if(l == r){
    return {1, (int)adj[l].size() - (l != 1)};
  }

  int mid = l + (r - l) / 2;
  vector<int> a = Solve(l, mid);
  vector<int> b = Solve(mid + 1, r);

  return MultiplyPolynomials(a, b);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  vector<int> f = Solve(1, n);

  int ans = 0;
  for(int i = 1, j = n - 1, fact = 1; i <= n; ++i, --j){
    fact = (1ll * i * fact) % MOD;
    int ansx = (1ll * f[j] * fact) % MOD;
    
    if(j % 2 == 1){
      ansx = MOD - ansx;
    }

    ans = (ans + ansx) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}