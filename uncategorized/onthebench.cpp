#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 301
#define MOD 1000000007

int a[N], b[N], c[N];
ll fact[N], C[N][N], dp[N][N];

bool IsPerfectSquare(ll a){
  ll x = sqrt(a) - 1;
  while(x * x < a)
    ++x;
  return (x * x == a);
}

void PreProcess(){
  C[0][0] = 1;
  for(int i = 1; i < N; ++i){
    C[i][0] = 1;
    for(int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
  }

  fact[0] = 1;
  for(int i = 1; i < N; ++i)
    fact[i] = (i * fact[i - 1]) % MOD;
}

int main(){
  int n, m = 0;

  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];

  for(int i = 1; i <= n; ++i){
    int j;
    for(j = i - 1; j > 0 && IsPerfectSquare(1ll * a[j] * a[i]) == 0; --j);
    if(j)
      b[i] = b[j];
    else
      b[i] = ++m;
    c[b[i]]++;
  }

  swap(n, m);

  PreProcess();

  m = 0;
  dp[0][0] = 1;
  int x = 0;

  for(int i = 0; i < n; ++i){
    int f = c[i + 1];
    for(int k = 0; k <= min(x + 1, f); ++k){
      for(int j = 0; j <= m; ++j){
        if(dp[i][j] == 0)
          continue;

        for(int l = 0; l <= min(j, k); ++l){
          if(k - l > x + 1 - j)
            continue;

          ll val = dp[i][j];
          val = (val * C[j][l]) % MOD;
          val = (val * C[x + 1 - j][k - l]) % MOD;
          val = (val * C[f - 1][k - 1]) % MOD;
          val = (val * fact[f]) % MOD;

          int jx = j - l + f - k;
          dp[i + 1][jx] = (dp[i + 1][jx] + val) % MOD;
        }
      }
    }

    m += (f - 1);
    x += f;
  }

  cout << dp[n][0] << '\n';

  return 0;
}
