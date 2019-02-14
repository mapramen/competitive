#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair



int main(){
  int m, d;
  vector<ll> v;

  scanf("%d%d", &m, &d);

  for(ll x = 1; m > 0; x += (d + 1)){
    int n;
    for(n = 1; (1 << n) - 1 <= m; ++n);
    --n;
    m -= ((1 << n) - 1);
    for(int i = 1; i <= n; ++i)
      v.PB(x);
  }

  printf("%lu\n", v.size());
  for(auto x : v)
    printf("%lld ", x);
  printf("\n");

  return 0;
}
