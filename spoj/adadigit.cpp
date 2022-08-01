#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000000000

vector<int> primes;

bool IsPrime(int n){
  for(int i = 2; i * i <= n; ++i){
    if(n % i == 0){
      return false;
    }
  }
  return true;
}

void Initialize(){
  for(int i = 2; i * i < N; ++i){
    if(IsPrime(i)){
      primes.push_back(i);
    }
  }
}

pll Calculate(int n){
  ll divisor_count = 1, divisor_sum = 1;

  for(int p: primes){
    if(p * p > n){
      break;
    }

    if(n % p != 0){
      continue;
    }

    int k = 1;
    ll prime_power_sum = 1;
    for( ; n % p == 0; n /= p){
      ++k, prime_power_sum = 1 + p * prime_power_sum;
    }

    divisor_count *= k, divisor_sum *= prime_power_sum;
  }

  if(n != 1){
    divisor_count *= 2, divisor_sum *= (1 + n);
  }

  return {divisor_count, divisor_sum};
}

int main(){
  Initialize();
  
  int n;
  scanf("%d", &n);

  string s;
  while(n--){
    int d;
    scanf("%d", &d);
    s.push_back('0' + d);
  }
  sort(s.begin(), s.end());

  ll max_divisor_count = 0, max_divisor_sum = 0;
  int max_divisor_count_number = 0, max_divisor_sum_number = 0;

  do
  {
    int number = stoi(s);
    
    ll divisor_count, divisor_sum;
    tie(divisor_count, divisor_sum) = Calculate(number);

    if(divisor_count > max_divisor_count){
      max_divisor_count = divisor_count, max_divisor_count_number = number;
    }

    if(divisor_sum > max_divisor_sum){
      max_divisor_sum = divisor_sum, max_divisor_sum_number = number;
    }
  } while(next_permutation(s.begin(), s.end()));

  printf("%d %d\n", max_divisor_count_number, max_divisor_sum_number);
  
  return 0;
}