#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  ll n, k;
  scanf("%lld%lld", &n, &k);

  if(n == -1){
    exit(0);
  }

  if(n == 0){
    printf("1\n");
    return;
  }

  ll m = k / 2;
  ll p = k % 2 == 1 ? m * m : m * (m - 1);
  ll q = n * (n - 1) / 2;

  if(p == 0){
    printf("0\n");
    return;
  }

  ll g = __gcd(p, q);
  p /= g, q /= g;
  
  printf("%lld/%lld\n", p, q);
}

int main(){
  while(true){
    Solve();
  }
  return 0;
}