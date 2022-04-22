#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define B 60

ll a[N];

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  for(int k = B - 1, x = 1; k != -1; --k){
    ll mask = (1ll << k);
    int i = x;
    for( ; i <= n && (a[i] & mask) == 0; ++i);
    if(i > n){
      continue;
    }

    swap(a[x], a[i]);

    for(int j = 1; j <= n; ++j){
      if(j == x || (a[j] & mask) == 0){
        continue;
      }
      a[j] ^= a[x];
    }

    ++x;
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ans ^= a[i];
  }

  printf("%lld\n", ans);

  return 0;
}