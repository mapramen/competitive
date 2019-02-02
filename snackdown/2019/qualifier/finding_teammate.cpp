#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define MOD 1000000007

int a[N];
ll fact[N], inv_fact[N];

ll ModExp(int a, int n){
  ll x = a, y = 1 % MOD;
  while(n){
    if(n % 2){
      y = (x * y) % MOD;
    }
    x = (x * x) % MOD;
    n /= 2;
  }
  return y;
}

ll ModInv(int a){
  return ModExp(a, MOD - 2);
}

void Initialise(){
  fact[0] = 1;
  for(int i = 1; i < N; ++i){
    fact[i] = (i * fact[i - 1]) % MOD;
  }
  inv_fact[N - 1] = ModInv((int)fact[N - 1]);
  for(int i = N - 2; i > -1; --i){
    inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % MOD;
  }
}

ll Compute(int n, int ones, int twos){
  ll ans = fact[n];
  ans = (ans * inv_fact[ones]) % MOD;
  ans = (ans * inv_fact[twos]) % MOD;
  while(twos--){
    ans = (ans * inv_fact[2]) % MOD;
  }
  return ans;
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i){
      scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1);

    ll ans = 1;

    int parity = 0;
    for(int i = 1; i <= n; ){
      int j = i;
      for( ; j <= n && a[j] == a[i]; ++j);

      int m = j - i, ones = (m - parity) % 2, twos = (m - parity) / 2;
      ans = (ans * Compute(m, ones, twos)) % MOD;

      parity = (parity + m) % 2;
      i = j;
    }

    printf("%lld\n", ans);
  }

  return 0;
}
