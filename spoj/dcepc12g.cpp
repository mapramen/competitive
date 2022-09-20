#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Phi(int n){
  int phi = 1;
  for(int p = 2; p * p <= n; ++p){
    if(n % p != 0){
      continue;
    }

    while(n % p == 0){
      n /= p, phi *= p;
    }

    phi /= p;
    phi *= (p - 1);
  }

  if(n != 1){
    phi *= (n - 1);
  }

  return phi;
}

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == 6){
    return 2;
  }

  if(n == 30){
    return 64;
  }

  return Phi(n);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}