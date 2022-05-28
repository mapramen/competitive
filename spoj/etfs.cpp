#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100000

ll d[N], phi[N];

int main(){
  ll a, b;
  scanf("%lld%lld", &a, &b);

  ll n = b - a + 1;
  for(ll i = a, j = 0; i <= b; ++i, ++j){
    d[j] = i, phi[j] = 1;
  }

  for(int i = 2; i < 1e7; ++i){
    for(int j = ((a + i - 1) / i) * i - a; j < n; j += i){
      if(d[j] % i != 0){
        continue;
      }

      while(d[j] % i == 0){
        phi[j] *= i, d[j] /= i;
      }

      phi[j] /= i;
      phi[j] *= (i - 1);
    }
  }

  for(int j = 0; j < n; ++j){
    if(d[j] == 1){
      continue;
    }
    phi[j] *= (d[j] - 1);
  }

  for(int j = 0; j < n; ++j){
    printf("%lld\n", phi[j]);
  }

  return 0;
}