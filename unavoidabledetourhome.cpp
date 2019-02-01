#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple< int, int >
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 51
#define MOD 1000000007

int n, d[N];
map< tiii, int > c;
map< tii, int > dp;

ll nCr(int n, int r){
  if(n < 0 || r < 0 || r > n)
    return 0ll;
  else if(r == 0)
    return 1ll;
  else{
    ll ans = 1;

    for(int i = 0; i < r; i++)
      ans *= (n - i);

    for(int i = 1; i <= r; i++)
      ans /= i;

    return ans;
  }
}

int GetC(int k, int i, int j){
  if(k < 0 || i < 0 || j < 0 || k > i + 2 * j)
    return 0;

  tiii t = MT(k, i, j);
  if(c.find(t) == c.end()){
    int ans = 0;
    if(j){
      ans = (ans + nCr(k, 2) * GetC(k - 2, i, j - 1)) % MOD;
      ans = (ans + nCr(i, 1) * nCr(k, 1) * GetC(k - 1, i - 1, j - 1)) % MOD;
      ans = (ans + nCr(j - 1, 1) * nCr(k, 1) * GetC(k - 1, i + 1, j - 2)) % MOD;
      ans = (ans + nCr(i, 2) * GetC(k, i - 2, j - 1)) % MOD;
      ans = (ans + nCr(i, 1) * nCr(j - 1, 1) * GetC(k, i, j - 2)) % MOD;
      ans = (ans + nCr(j - 1, 2) * GetC(k, i + 2, j - 3)) % MOD;
    }
    else{
      ans = (ans + nCr(k, 1) * GetC(k - 1, i - 1, j)) % MOD;
      ans = (ans + nCr(i - 1, 1) * GetC(k, i - 2, j)) % MOD;
    }

    c[t] = ans;
  }

  // printf("GetC %d %d %d: %d\n", k, i, j, c[t]);

  return c[t];
}

int Solve(int i, int l){
  if((i >= n + 2) || (i == n + 1 && l != 0) || (i <= n && l == 0))
    return 0;

  tii t = MT(i, l);
  if(dp.find(t) == dp.end()){
    int ones = 0, twos = 0, ans = 0;
    for(int x = i; x <= n && x < i + l; x++){
      ones += (d[x] == 1);
      twos += (d[x] == 2);
    }

    for(int k = 0; k <= ones + 2 * twos; k++)
      ans = (ans + 1ll * GetC(k, ones, twos) * Solve(i + l, k)) % MOD;

    dp[t] = ans;
  }

  // printf("Solve %d %d: %d\n", i, l, dp[t]);

  return dp[t];
}

int main(){
  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &d[i]);

  for(int i = 2; i <= n; i++)
    d[i]--;

  c[MT(0, 0, 0)] = 1;
  dp[MT(n + 1, 0)] = 1;

  printf("%d\n", Solve(2, d[1]));

  return 0;
}
