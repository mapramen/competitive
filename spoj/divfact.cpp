#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 50001
#define MOD 1000000007

vector<int> primes;

void Initialise(){
  for(int i = 2; i < N; ++i){
    bool is_prime = true;
    for(int j = 2; j * j <= i && is_prime; ++j){
      is_prime = i % j != 0;
    }
    if(is_prime){
      primes.push_back(i);
    }
  }
}

int PowerInFactorial(int n, int p){
  int ans = 0;
  while(n >= p){
    n /= p;
    ans += n;
  }
  return ans;
}

int Solve(){
  int n;
  scanf("%d", &n);

  int ans = 1;
  for(int prime: primes){
    ans = (1ll * (1 + PowerInFactorial(n, prime)) * ans) % MOD;
  }

  return ans;
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