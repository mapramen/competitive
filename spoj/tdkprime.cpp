#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100000000
#define B 100000

vector<int> small_primes, primes(1);
bool is_prime[B];

bool IsPrime(int n){
  for(int i = 2; i * i <= n; ++i){
    if(n % i == 0){
      return false;
    }
  }
  return true;
}

void SegmentedSieve(int l, int r){
  int n = r - l + 1;
  for(int i = 0; i < n; ++i){
    is_prime[i] = true;
  }

  for(int p: small_primes){
    if(p * p > r){
      break;
    }

    for(int i = max(p, l / p + (l % p != 0)) * p - l; i < n; i += p){
      is_prime[i] = false;
    }
  }

  for(int i = 0; i < n; ++i){
    if(!is_prime[i]){
      continue;
    }
    primes.push_back(l + i);
  }
}

void Initialise(){
  for(int i = 2; i < 11000; ++i){
    if(IsPrime(i)){
      small_primes.push_back(i);
    }
  }

  for(int i = 2, c = 0; i <= N; i += B){
    SegmentedSieve(i, min(N, i + B - 1));
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return primes[n];
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}