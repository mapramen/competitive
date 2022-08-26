#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 20

int c[B];

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    
    for(int k = 0; k < B; ++k){
      c[k] += ((x & (1 << k)) != 0);
    }
  }

  ll ans = 0;
  for(int k = 0; k < B; ++k){
    ans += 1ll * c[k] * (n - c[k]) * (1 << k);
  }

  printf("%lld\n", ans);
  
  return 0;
}