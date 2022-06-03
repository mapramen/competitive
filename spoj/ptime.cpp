#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool IsPrime(int n){
  for(int i = 2; i * i <= n; ++i){
    if(n % i == 0){
      return false;
    }
  }
  return true;
}

int PrimePowerInFactorial(int n, int p){
  int ans = 0;
  for( ; n >= p; n /= p){
    ans += n / p;
  }
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int p = 2, print_separator = false; p <= n; ++p){
    if(!IsPrime(p)){
      continue;
    }

    if(print_separator){
      printf(" * ");
    }

    printf("%d^%d", p, PrimePowerInFactorial(n, p));
    print_separator = true;
  }
  printf("\n");

  return 0;
}