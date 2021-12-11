#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007
#define N 1000000

int c[2 * N + 5], fact[N + 1];

void Initialise(){
  fact[0] = 1;
  for(int i = 1; i <= N; ++i){
    fact[i] = (1ll * i * fact[i - 1]) % MOD;
  }
}

void Update(int i, int x){
  i += N;
  c[i] += x;
}

void UpdateRange(int l, int r){
  Update(l, 1);
  Update(r + 2, -1);
}

int main(){
  int n;
  scanf("%d", &n);

  while(n--){
    int x;
    scanf("%d", &x);
    UpdateRange(1 - x, x - 1);
  }

  Initialise();

  int ans = 0, mul = 1;
  for(int i = 0, s = 0; i < 2 * N; ++i){
    int k = i - N, x = c[i];

    int ansx = (1ll * x * s + 1ll * x * (x + 1) / 2) % MOD;
    ans = (ans + 1ll * k * ansx) % MOD;

    mul = (1ll * mul * fact[x]) % MOD;

    c[i + 2] += x;
    s = (s + x) % MOD;
  }

  ans = (ans + MOD) % MOD;

  printf("%d %d\n", ans, mul);

  return 0;
}