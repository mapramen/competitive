#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define MOD 998244353

int a[3][3], c[3], fact[N], inv_fact[N];

int GetMappedValue(char c){
  if(c == 'W'){
    return 0;
  }

  if(c == 'B'){
    return 1;
  }

  return 2;
}

int ModExp(int a, int n){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

int ModInv(int a){
  return ModExp(a, MOD - 2);
}

void Initialise(){
  fact[0] = 1;
  for(int i = 1; i < N; ++i){
    fact[i] = (1ll * i * fact[i - 1]) % MOD;
  }

  inv_fact[N - 1] = ModInv(fact[N - 1]);
  for(int i = N - 2; i > -1; --i){
    inv_fact[i] = (1ll * (i + 1) * inv_fact[i + 1]) % MOD;
  }
}

int nCr(int n, int r){
  if(n < 0 || r < 0 || n < r){
    return 0;
  }

  int q = (1ll * inv_fact[r] * inv_fact[n - r]) % MOD;
  return (1ll * fact[n] * q) % MOD;
}

void ReadString(int n){
  char s[3];
  while(n--){
    scanf("%s", s);
    ++a[GetMappedValue(s[0])][GetMappedValue(s[1])];
  }
}

int CalculateAns(int n){
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      c[i] += a[i][j], c[j] += a[i][j];
    }
  }

  if(max(c[0], c[1]) > n){
    return 0;
  }

  Initialise();

  int ans = nCr(c[2], n - c[0]);

  if(a[0][0] != 0 || a[1][1] != 0){
    return ans;
  }

  int wb = a[0][1] + a[0][2] + a[2][1], bw = a[1][0] + a[2][0] + a[1][2], qq = a[2][2];
  int ansx = 1;
  while(qq--){
    ansx = (2 * ansx) % MOD;
  }

  if(wb == 0){
    --ansx;
  }

  if(bw == 0){
    --ansx;
  }

  return (MOD + ans - ansx) % MOD;
}

int main(){
  int n;
  scanf("%d", &n);

  ReadString(n);

  printf("%d\n", CalculateAns(n));

  return 0;
}