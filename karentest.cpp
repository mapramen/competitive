#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define MOD 1000000007


int a[N], fact[N], inv_fact[N];

int ModExp(int a, int n){
  int ans = 1 % MOD;
  while(n){
    if(n % 2)
      ans = (1ll * ans * a) % MOD;
    a = (1ll * a * a) % MOD;
    n /= 2;
  }
  return ans;
}

int ModInverse(int a){
  return ModExp(a, MOD - 2);
}

void Initialise(){
  fact[0] = inv_fact[0] = 1 % MOD;
  for(int i = 1; i < N; i++){
    fact[i] = (1ll * i * fact[i - 1]) % MOD;
    inv_fact[i] = (1ll * ModInverse(i) * inv_fact[i - 1]) % MOD;
  }
}

int nCr(int n, int r){
  if(n < 0 || r < 0 || n < r)
    return 0;
  else{
    int ans = fact[n];
    ans = (1ll * ans * inv_fact[r]) % MOD;
    ans = (1ll * ans * inv_fact[n - r]) % MOD;
    return ans;
  }
}

int main(){
  int n, k = 1, ans;

  Initialise();

  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  if(n > 1 && n % 2 == 1){
    for(int i = 1; i < n; i++){
      a[i] = (a[i] + k * a[i + 1]) % MOD;
      a[i] = (MOD + a[i]) % MOD;
      k *= -1;
    }
    n--;
  }

  if(n > 2){
    int a1 = 0, a2 = 0, m = n / 2 - 1;
    for(int i = 0; i <= m; i++){
      a1 = (a1 + 1ll * nCr(m, i) * a[2 * i + 1]) % MOD;
      a2 = (a2 + 1ll * nCr(m, i) * a[2 * i + 2]) % MOD;
    }

    if(n % 4 == 0)
      k *= -1;

    a[1] = a1, a[2] = a2;
  }

  for(int i = 1; i < n; i++){
    a[i] = (a[i] + k * a[i + 1]) % MOD;
    a[i] = (MOD + a[i]) % MOD;
    k *= -1;
  }
  n--;

  ans = a[1];

  printf("%d\n", ans);

  return 0;
}
