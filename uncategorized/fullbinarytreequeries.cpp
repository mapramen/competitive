#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 60

vector<ll> v(B), s(B);

int main(){
  for(int i = 0; i < B; ++i)
    v[i] = (1ll << i);

  int q;
  scanf("%d", &q);

  while(q--){
    int t;
    ll x, k = 0;

    scanf("%d%lld", &t, &x);

    if(t <= 2){
      scanf("%lld\n", &k);
    }

    int h;
    for(h = 0; h < B && v[h] <= x; ++h);
    --h;

    if(t <= 2){
      for(int i = h, j = t == 1 ? h : B - 1; i <= j; ++i){
        ll mod = v[i], y = (mod - k % mod) % mod;
        s[i] = (s[i] + y) % mod;
        k *= 2;
      }
    }
    else{
      x = v[h] + (x + v[h] - s[h]) % v[h];
      for( ; h > -1; --h){
        ll mod = v[h];
        printf("%lld ", mod + (x + s[h]) % mod);
        x /= 2;
      }
      printf("\n");
    }
  }

  return 0;
}
