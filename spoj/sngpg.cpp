#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define NO_BASE_PRIMES 10

int cnt[N];
vector<ll> basePrimes;

ll Multiply(ll a, ll b, ll MOD){
  ull c = ((long double) a * b / MOD) - 1;
  return (ll)((a * b - c * MOD) % MOD);
}

ll ModExp(ll a, ll n, ll MOD){
  ll x = a, y = 1ll % MOD;
  while(n){
    if(n % 2){
      y = Multiply(y, x, MOD);
    }
    x = Multiply(x, x, MOD);
    n /= 2;
  }
  return y;
}

bool PrimalityCheck(ll n){
  bool isPrime = 1;
  ll r, d;
  for(r = 0; __gcd(1ll << (r + 1), n - 1) == (1ll << (r + 1)); r++);
  d = (n - 1) / (1ll << r);

  for(auto p : basePrimes){
    ll x = ModExp(p, d, n);
    if(x == 1 || x == n - 1 || p == n)
      continue;
    else{
      ll k;
      for(k = 1; k < r; k++){
        x = Multiply(x, x, n);
        if(x == 1)
          isPrime = 0;
        if(x == n - 1)
          break;
      }
      if(k != r && isPrime == 1)
        continue;
      else{
        isPrime = 0;
        break;
      }
    }
  }

  return isPrime;
}

bool IsPrime(ll n){
  if(n == 1){
    return true;
  }

  bool isPrime = 1;

  if(n > 2 && n % 2 == 0)
    isPrime = 0;
  else
    isPrime = PrimalityCheck(n);

  return isPrime;
}

void Initialize(){
  for(ll n = 2; basePrimes.size() < NO_BASE_PRIMES; n++){
    ll i;
    for(i = 2; i * i <= n && n % i != 0; i++);
    if(i * i > n){
      basePrimes.push_back(n);
    }
  }

  for(int i = 0; i < N; ++i){
    cnt[i] = 1;
  }

  for(int i = 2; i * i < N; ++i){
    if(cnt[i] == 0){
      continue;
    }

    for(int j = i * i; j < N; j += i){
      cnt[j] = 0;
    }
  }

  for(int i = 0; i < N; ++i){
    if(cnt[i] == 1){
      cnt[i] = IsPrime(1ll * i * i + 1) || IsPrime(1ll * i * i + 2);
    }
  }

  for(int i = 1; i < N; ++i){
    cnt[i] += cnt[i - 1];
  }
}

int GetCount(int i){
  return i >= 0 ? cnt[i] : 0;
}

int Solve(){
  int l, r;
  scanf("%d%d", &l, &r);
  return GetCount(r) - GetCount(l - 1);
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}