#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<pii> GetPrimeFactors(int n){
  vector<pii> prime_factors;
  for(int i = 2; i * i <= n; ++i){
    if(n % i != 0){
      continue;
    }

    int k = 0;
    while(n % i == 0){
      ++k, n /= i;
    }

    prime_factors.push_back({i, k});
  }

  if(n != 1){
    prime_factors.push_back({n, 1});
  }

  return prime_factors;
}

int PrimePowerInFactorial(int n, int p){
  int ans = 0;
  for( ; n >= p; n /= p){
    ans += n / p;
  }
  return ans;
}

bool Check(vector<pii>& prime_factors, int n){
  for(pii& prime_factor: prime_factors){
    if(PrimePowerInFactorial(n, prime_factor.first) < prime_factor.second){
      return false;
    }
  }
  return true;
}

int GetMinimalDivisibleFactorial(int n){
  vector<pii> prime_factors = GetPrimeFactors(n);

  int x = 1, y = n, ans = n;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(prime_factors, mid)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }

  return ans;
}

int main(){
  int a, b;
  scanf("%d%d", &a, &b);

  int ans = max(0, GetMinimalDivisibleFactorial(b) - GetMinimalDivisibleFactorial(a));
  printf("%d\n", ans);

  return 0;
}