#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

const ll M = 1000000000000000000;
bool isPrime[N];
vector<int> primes;
vector<ll> c(1);

bool IsSquare(ll x){
  ll n = sqrt(max(0ll, x - 1));
  while(n * n < x){
    ++n;
  }
  return n * n == x;
}

void Initialise(){
  for(int i = 2; i < N; ++i){
    isPrime[i] = 1;
  }

  for(int i = 2; i < N; ++i){
    if(isPrime[i] == 0){
      continue;
    }
    primes.PB(i);
    for(int j = 2 * i; j < N; j += i){
      isPrime[j] = 0;
    }
  }

  set<ll> S;
  for(int i = 3; i < 60; ++i){
    if(isPrime[i] == 0){
      continue;
    }

    set<ll> U;
    U.insert(1ll);
    for(auto prime : primes){
      ll x = M, y = 1;
      for(int k = 0; k < i && x > 0; x /= prime, y *= prime, ++k);
      if(x == 0){
        break;
      }
      x = 0;
      ll z = M / y;
      while(true){
        auto it = U.upper_bound(x);
        if(it == U.end()){
          break;
        }
        x = *it;
        if(x <= z){
          U.insert(x * y);
        }
        else{
          break;
        }
      }
    }

    for(auto x : U){
      S.insert(x);
    }
  }

  for(auto x : S){
    if(!IsSquare(x)){
      c.PB(x);
    }
  }
}

ll SquareRoot(ll n){
  ll x = sqrt(max(0ll, n - 1));
  while(x * x <= n){
    ++x;
  }
  return x - 1;
}

int main(){
  int t;

  scanf("%d", &t);

  Initialise();

  while(t--){
    ll n;
    scanf("%lld", &n);
    ll ans = SquareRoot(n);
    ans += (upper_bound(c.begin(), c.end(), n) - c.begin() - 1);
    ans = n - ans;
    printf("%lld\n", ans);
  }

  return 0;
}
