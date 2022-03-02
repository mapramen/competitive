#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100000000
#define B 100000

vector<int> primes;
bool is_prime[B];

bool IsPrime(int n){
  for(int i = 2; i * i <= n; ++i){
    if(n % i == 0){
      return false;
    }
  }
  return true;
}

void Initialise(){
  for(int i = 2; i < 11000; ++i){
    if(IsPrime(i)){
      primes.push_back(i);
    }
  }
}

int SegmentedSieve(int l, int r, int c){
  int n = r - l + 1;
  for(int i = 0; i < n; ++i){
    is_prime[i] = true;
  }

  for(int p: primes){
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
    if(++c % 100 == 1){
      printf("%d\n", l + i);
    }
  }

  return c;
}

int main(){
  Initialise();

  for(int i = 2, c = 0; i <= N; i += B){
    c = SegmentedSieve(i, min(N, i + B - 1), c);
  }

  return 0;
}