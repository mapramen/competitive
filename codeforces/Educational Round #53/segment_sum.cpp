#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 20
#define B 10
#define M (1 << B)
#define MOD 998244353

ll dpCount[N][M][B + 1], dpSum[N][M][B + 1], p10[N];

void Initialise(){
  p10[0] = 1 % MOD;
  for(int i = 1; i < N; ++i){
    p10[i] = (10 * p10[i - 1]) % MOD;
  }

  for(int j = 2; j < M; ++j){
    for(int k = __builtin_popcount(j); k <= B; ++k){
      dpCount[0][j][k] = (1 % MOD);
    }
  }

  for(int i = 1; i < N; ++i){
    for(int k = 0; k <= B; ++k){
      dpSum[i][1][k] = (dpSum[i][1][k] + dpSum[i - 1][1][k]) % MOD;
    }

    for(int j = 2; j < M; ++j){
      for(int k = 0; k <= B; ++k){
        for(int x = 0, p = 0; x < B; ++x, p = (p + p10[i - 1]) % MOD){
          int nj = (j | (1 << x));
          int valCount = dpCount[i - 1][nj][k], valSum = (1ll * valCount * p + dpSum[i - 1][nj][k]) % MOD;
          dpCount[i][j][k] = (dpCount[i][j][k] + valCount) % MOD;
          dpSum[i][j][k] = (dpSum[i][j][k] + valSum) % MOD;
          if(x && j == (1 << x)){
            dpSum[i][1][k] = (dpSum[i][1][k] + valSum) % MOD;
          }
        }
      }
    }
  }
}

ll Solve(ll n, ll k){
  if(n == 0){
    return 0ll;
  }

  vector<int> v;
  for(ll m = n; m > 0; m /= 10){
    v.PB(m % 10);
  }

  int prefixMask = 0;
  ll ans = 0;
  for(int y = 0, p = 0; v.size(); y = 1){
    int d = v.back();
    v.pop_back();
    int i = v.size();
    p = (10ll * p) % MOD;
    for(int x = 0; x < d; ++x, p = (p + 1) % MOD){
      int j = (prefixMask | (1 << x));
      ll ansx = (dpCount[i][j][k] * p10[i]) % MOD;
      ansx = (p * ansx) % MOD;
      ans = (ans + ansx + dpSum[i][j][k]) % MOD;
    }
    prefixMask |= (1 << d);
  }

  ans = (ans + n * dpCount[0][prefixMask][k]) % MOD;

  return ans;
}

int main(){
  ll a, b, k, ans;
  Initialise();
  cin >> a >> b >> k;
  ans = (MOD + Solve(b, k) - Solve(a - 1, k)) % MOD;
  cout << ans << '\n';
  return 0;
}
