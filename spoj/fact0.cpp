#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  ll n;
  scanf("%lld", &n);

  if(n == 0){
    exit(0);
  }

  for(ll i = 2; i * i <= n; ++i){
    if(n % i != 0){
      continue;
    }

    int k = 0;
    while(n % i == 0){
      ++k, n /= i;
    }

    printf("%lld^%d ", i, k);
  }

  if(n != 1){
    printf("%lld^1", n);
  }

  printf("\n");
}

int main(){
  while(true){
    Solve();
  }
  return 0;
}