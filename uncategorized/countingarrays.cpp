#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000020
#define MOD 1000000007

int leastPrime[N];
ll fact[N], inv_fact[N], p2[N];

ll ModExp(ll a, ll n){
  ll ans = 1 % MOD;
  while(n){
    if(n % 2)
      ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    n /= 2;
  }
  return ans;
}

ll ModInv(ll a){
  return ModExp(a, MOD - 2);
}

void PreProcess(){
  fact[0] = inv_fact[0] = p2[0] = 1;

  for(int i = 1; i < N; ++i)
    fact[i] = (i * fact[i - 1]) % MOD;

  inv_fact[N - 1] = ModInv(fact[N - 1]);
  for(int i = N - 2; i > 0; --i)
    inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % MOD;

  for(int i = 1; i < N; ++i)
    p2[i] = (2 * p2[i - 1]) % MOD;

  for(int i = 2; i < N; ++i)
    for(int j = i; j < N; j += i)
      if(leastPrime[j] == 0)
        leastPrime[j] = i;
}

int nCr(int n, int r){
  if(n < 0 || r < 0 || n < r)
    return 0;
  else{
    ll ans = fact[n];
    ans = (ans * inv_fact[n - r]) % MOD;
    ans = (ans * inv_fact[r]) % MOD;
    return (int)ans;
  }
}

int Query(int n, int m){
  ll ans = p2[m - 1];

  while(n > 1){
    int k = leastPrime[n], c = 0;
    while(n % k == 0){
      ++c;
      n /= k;
    }
    ans = (ans * nCr(c + m - 1, m - 1)) % MOD;
  }

  return (int)ans;
}

int main(){
  PreProcess();

  int q;
  scanf("%d", &q);
  while(q--){
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", Query(n, m));
  }
  return 0;
}
