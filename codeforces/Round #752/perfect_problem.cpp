#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 205

int n, mod, fact[N], inv_fact[N], a1;
int marker[N][N][N], dp[N][N][N];

int ModularExponentation(int a, int n){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 != 0){
      ans = (1ll * a * ans) % mod;
    }
    a = (1ll * a * a) % mod;
  }
  return ans;
}

int ModularInverse(int a){
  return ModularExponentation(a, mod - 2);
}

void Initialise(){
  fact[0] = 1;
  for(int i = 1; i < N; ++i){
    fact[i] = (1ll * i * fact[i - 1]) % mod;
  }

  inv_fact[N - 1] = ModularInverse(fact[N - 1]);
  for(int i = N - 2; i > -1; --i){
    inv_fact[i] = (1ll * (i + 1) * inv_fact[i + 1]) % mod;
  }
}

int DP(int i, int j, int k){
  if(k > j || (i > a1 && k <= i - a1)){
    return 0;
  }

  if(k == 0){
    return j == 0 ? (1ll * fact[n] * inv_fact[i]) % mod : 0;
  }

  if(marker[i][j][k] == a1){
    return dp[i][j][k];
  }

  int ans = 0;
  for(int ni = i - 1, nj = j - k, cnt = 1; ni > 0 && nj >= 0; --ni, nj -= k, ++cnt){
    int ansx = 0;
    for(int nk = k - 1; nk >= 0; --nk){
      ansx = (ansx + DP(ni, nj, nk)) % mod;
    }
    ansx = (1ll * ansx * inv_fact[cnt]) % mod;
    ans = (ans + ansx) % mod;
  }

  marker[i][j][k] = a1;
  dp[i][j][k] = ans;
  return ans;
}

int main(){
  cin >> n >> mod;

  Initialise();

  int ans = 1;
  for(a1 = max(1, (int)(max(0.0, n - sqrt(2 * n) - 1))); a1 <= n + 1; ++a1){
    for(int j = n + 1 - a1; j <= a1; ++j){
      ans = (ans + DP(n, j, n + 1 - a1)) % mod;
    }
  }

  cout << ans << '\n';

  return 0;
}