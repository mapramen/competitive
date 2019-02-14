#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define NO_BASE_PRIMES 10

vector<ll> basePrimes;

void Initialize(){
  for(ll n = 2; basePrimes.size() < NO_BASE_PRIMES; n++){
    ll i;
    for(i = 2; i * i <= n && n % i != 0; i++);
    if(i * i > n)
      basePrimes.PB(n);
  }
}

ll Multiply(ll a, ll b, ll MOD){
  ull c = ((long double) a * b / MOD) - 1;
  return (ll)((a * b - c * MOD) % MOD);
}

ll ModExp(ll a, ll n, ll MOD){
  ll x = a, y = 1ll % MOD;
  while(n){
    if(n % 2)
      y = Multiply(y, x, MOD);
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
  bool isPrime = 1;

  if(n < 2 || (n > 2 && n % 2 == 0))
    isPrime = 0;
  else
    isPrime = PrimalityCheck(n);

  return isPrime;
}

int main(){
  Initialize();

  int t;
  cin >> t;
  while(t--){
    int c = 0, m = -1;
    string s;

    cin >> s;
    for(int i = 0; i < s.size(); ++i){
      if(s[i] < '0' || s[i] > '9')
        continue;
      ll n = 0;
      for( ; i < s.size(); ++i){
        if(s[i] < '0' || s[i] > '9')
          break;
        n = 10 * n + (s[i] - '0');
      }
      if(IsPrime(n)){
        ++c;
        m = max(m, (int)n);
      }
    }

    printf("%d %d\n", c, m);
  }

  return 0;
}
