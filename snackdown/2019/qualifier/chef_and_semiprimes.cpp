#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 201

bool isPrime[N], isSemiPrime[N], isValid[N];

void Initialize(){
  for(int i = 2; i < N; ++i){
    isPrime[i] = 1;
  }

  vector<int> primes, semiprimes;
  for(int i = 2; i < N; ++i){
    if(isSemiPrime[i]){
      semiprimes.PB(i);
      for(auto j : semiprimes){
        int k = i + j;
        if(k >= N){
          break;
        }
        isValid[k] = 1;
      }
    }

    if(isPrime[i]){
      for(auto j : primes){
        int k = i * j;
        if(k >= N){
          break;
        }
        isSemiPrime[k] = 1;
      }

      for(int j = i + i; j < N; j += i){
        isPrime[j] = 0;
      }

      primes.PB(i);
    }
  }
}

int main(){
  Initialize();

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << (isValid[n] ? "YES" : "NO") << '\n';
  }

  return 0;
}
