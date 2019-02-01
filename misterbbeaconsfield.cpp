#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MAXN 1000001
#define B 15

ll smallestPrimeDivisor[MAXN], n[4], m[4], s[4], c[B], divisors[MAXN];

void Initialise(){
  for(int i = 2; i < MAXN; i++){
    for(int j = i; j < MAXN; j += i){
      if(smallestPrimeDivisor[j] == 0)
        smallestPrimeDivisor[j] = i;
    }
  }
}

ll GetPower(ll n, ll p){
  ll ans = 0;
  while(n % p == 0){
    n /= p;
    ans++;
  }
  return ans;
}

int GetTotalValidPrimes(ll N, ll S){
  int totalValidPrimes = 0;
  set<ll> d;
  d.insert(2);

  for(int i = 1; i <= 3; i++){
    ll x = n[i];
    while(x > 1){
      d.insert(smallestPrimeDivisor[x]);
      x /= smallestPrimeDivisor[x];
    }
  }

  for(int i = 1; i <= 3; i++){
    ll x = s[i];
    while(x > 1){
      d.insert(smallestPrimeDivisor[x]);
      x /= smallestPrimeDivisor[x];
    }
  }

  S *= 2;
  for(auto x : d){
    if(GetPower(N, x) <= GetPower(S, x))
      continue;

    ll y = GetPower(S, x) + 1, z = 1;
    while(y--)
      z *= x;
    c[totalValidPrimes++] = z;
  }

  return totalValidPrimes;
}

int main(){
  Initialise();
  int t;
  scanf("%d", &t);
  while(t--){
    ll N = 1, M = 1, S = 1, ans = 0;
    map< ll, ll > d;
    vector<ll> v;

    for(int i = 1; i <= 3; i++){
      scanf("%lld", &n[i]);
      N *= n[i];
    }

    for(int i = 1; i <= 3; i++){
      scanf("%lld", &m[i]);
      M *= m[i];
    }

    for(int i = 1; i <= 3; i++){
      scanf("%lld", &s[i]);
      S *= s[i];
    }

    int totalValidPrimes = GetTotalValidPrimes(N, S);

    ans = M;
    for(int mask = 1; mask < (1 << totalValidPrimes); mask++){
      int validPrimes = __builtin_popcount(mask);
      ll ansx = M;
      for(int i = 0; i < totalValidPrimes; i++){
        if((mask & (1 << i)) > 0)
          ansx /= c[i];
      }
      if(validPrimes % 2 == 1)
        ans -= ansx;
      else
        ans += ansx;
    }

    d[2]++;
    for(int i = 1; i <= 3; i++){
      ll x = s[i];
      while(x > 1){
        d[smallestPrimeDivisor[x]]++;
        x /= smallestPrimeDivisor[x];
      }
    }

    divisors[0] = 1;
    int totalDivisors = 1;
    for(auto p : d){
      ll sz = totalDivisors, x = 1, y, z;
      tie(y, z) = p;
      while(z--){
        x *= y;
        for(int i = 0; i < sz; i++)
          divisors[totalDivisors++] = x * divisors[i];
      }
    }

    for(int i = 0; i < totalDivisors; i++)
      ans += (divisors[i] <= N);

    printf("%lld\n", ans);
  }

  return 0;
}
