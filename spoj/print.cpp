#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

vector<int> primes;
bool isPrime[N];

void Initialise(){
  for(int i = 2; i < N; ++i){
    isPrime[i] = true;
  }

  for(int i = 2; i * i < N; ++i){
    if(!isPrime[i]){
      continue;
    }

    for(int j = i * i; j < N; j += i){
      isPrime[j] = false;
    }
  }

  for(int i = 0; i < N; ++i){
    if(isPrime[i]){
      primes.push_back(i);
    }
    isPrime[i] = false;
  }
}

void Solve(){
  int l, r;
  scanf("%d%d", &l, &r);

  int n = r - l + 1;
  for(int k = 0; k < n; ++k){
    isPrime[k] = true;
  }

  if(l == 1){
    isPrime[0] = false;
  }

  for(int prime: primes){
    if(1ll * prime * prime > r){
      break;
    }

    int k = 1ll * (max(prime, (l + prime - 1) / prime)) * prime - l;
    for( ; k < n; k += prime){
      isPrime[k] = false;
    }
  }

  for(int k = 0; k < n; ++k){
    if(isPrime[k]){
      printf("%d\n", l + k);
    }
  }
}

int main(){
  int t;
  scanf("%d", &t);

  Initialise();
  while(t--){
    Solve();
  }
  
  return 0;
}