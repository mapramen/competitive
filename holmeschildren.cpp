#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define MOD 1000000007

bool isPrime[N];
vector< ll > primes;
map< ll, ll > m;

void AddPrimeFactors(ll n){
  for(ll i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++){
    ll j = 0;
    while(n % primes[i] == 0){
      j++;
      n /= primes[i];
    }

    if(j != 0){
      m[primes[i]] += j;
    }
  }

  if(n != 1)
    m[n]++;
}

void CalculateNext(){
  map< ll, ll > c;

  for(auto mx : m)
    c.insert(mx);

  m.clear();

  for(auto cx : c){
    ll p, k;
    tie(p, k) = cx;

    if(k > 1)
      m[p] += (k - 1);

    AddPrimeFactors(p - 1);
  }
}

ll CalculateAns(){
  ll ans = 1;
  for(auto mx : m){
    ll p, k, ansx;
    tie(p, k) = mx;
    ans *= (p - 1);
    k--;
    while(k--)
      ans *= p;
  }
  return ans;
}

int main(){
  ll n, k, ans;

  for(ll i = 2; i * i < N; i++){
    if(isPrime[i] == 0){
      for(ll j = i + i; j < N; j += i){
        isPrime[j] = 1;
      }
    }
  }

  for(ll i = 2; i < N; i++)
    if(isPrime[i] == 0){
      primes.PB(i);
    }

  cin >> n >> k;
  k = (k + 1) / 2;
  k--;

  AddPrimeFactors(n);
  n = CalculateAns();

  while(n != 1 && k > 0){
    CalculateNext();
    n = CalculateAns();
    k--;
  }

  cout << n % MOD << '\n';

  return 0;
}
