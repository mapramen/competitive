#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

int ModularExponentation(int a, int n){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

int ModularInverse(int a){
  return ModularExponentation(a, MOD - 2);
}

int Solve(){
  int n, m, rb, cb, rd, cd, p;
  scanf("%d%d%d%d%d%d%d", &n, &m, &rb, &cb, &rd, &cd, &p);

  int q = 100 - p;
  p = (1ll * p * ModularInverse(100)) % MOD;
  q = (1ll * q * ModularInverse(100)) % MOD;

  int T = 4 * (n - 1) * (m - 1);
  int Q = 1;

  int ans = 0;
  for(int i = 0, dr = 1, dc = 1; i < T; ++i){
    if(rb == rd || cb == cd){
      int ansx = (1ll * Q * p) % MOD;
      ansx = (1ll * ansx * i) % MOD;

      ans = (ans + ansx) % MOD;
      Q = (1ll * Q * q) % MOD;
    }

    if(rb == 1 && dr == -1){
      dr = 1;
    }

    if(rb == n && dr == 1){
      dr = -1;
    }

    if(cb == 1 && dc == -1){
      dc = 1;
    }

    if(cb == m && dc == 1){
      dc = -1;
    }

    rb += dr, cb += dc;
  }

  ans = (ans + 1ll * Q * T) % MOD;
  Q = (MOD + 1 - Q) % MOD;

  ans = (1ll * ans * ModularInverse(Q)) % MOD;

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