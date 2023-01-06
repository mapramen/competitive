#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

bool is_prime[N];
vector<int> primes, pp_primes;

bool IsPalindrome(int n){
  string s = to_string(n);
  reverse(s.begin(), s.end());
  return s == to_string(n);
}

void Initialize(){
  for(int i = 2; i < N; ++i){
    is_prime[i] = true;
  }

  for(int i = 2; i * i < N; ++i){
    if(!is_prime[i]){
      continue;
    }

    for(int j = i * i; j < N; j += i){
      if(is_prime[j]){
        is_prime[j] = false;
      }
    }
  }

  for(int i = 2; i < N; ++i){
    if(!is_prime[i]){
      continue;
    }

    primes.push_back(i);

    if(!IsPalindrome(i)){
      continue;
    }
    
    pp_primes.push_back(i);
  }
}

int GetNonZeroDigitProduct(int n){
  int ans = 1;
  for( ; n != 0; n /= 10){
    int d = n % 10;
    if(d != 0){
      ans *= d;
    }
  }
  return ans;
}

pii Solve(){
  int n;
  scanf("%d", &n);
  return {pp_primes[n - 1], primes[GetNonZeroDigitProduct(pp_primes[n - 1]) - 1]};
}

int main(){
  Initialize();
  int t;
  scanf("%d", &t);
  while(t--){
    pii ans = Solve();
    printf("%d %d\n", ans.first, ans.second);
  }
  return 0;
}