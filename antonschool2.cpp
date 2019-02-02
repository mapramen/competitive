#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define MOD 1000000007

int fact[N], inv_fact[N];

int ModExp(int a, int n){
  ll x = a, ans = 1 % MOD;

  while(n > 0){
    if(n % 2)
      ans = (ans * x) % MOD;
    x = (x * x) % MOD;
    n /= 2;
  }

  return (int)ans;
}

int ModInverse(int a){
  return ModExp(a, MOD - 2);
}

void PreProcess(int n){
  fact[0] = 1;
  for(int i = 1; i <= n; i++)
    fact[i] = (1ll * i * fact[i - 1]) % MOD;

  inv_fact[n] = ModInverse(fact[n]);
  for(int i = n - 1; i >= 0; i--)
    inv_fact[i] = (1ll * (i + 1) * inv_fact[i + 1]) % MOD;
}

int nCr(int n, int r){
  if(n < 0 || r < 0 || n < r)
    return 0;
  else{
    ll p = fact[n], q = (1ll * inv_fact[r] * inv_fact[n - r]) % MOD;
    return (int)((p * q) % MOD);
  }
}

int main(){
  int n, x = 0, y = 0, ans = 0;
  string s;

  cin >> s;
  n = s.size();

  for(int i = 0; i < n; i++)
    y += (s[i] == ')');

  PreProcess(n);

  for(int i = 0; i < n; i++){
    x += (s[i] == '(');
    y -= (s[i] == ')');

    if(s[i] == '(')
      ans = (ans + nCr(x + y - 1, x)) % MOD;
  }

  cout << ans << '\n';
  
  return 0;
}
