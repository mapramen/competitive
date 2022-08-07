#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll LG(int n){
  return n == 1 ? 0 : 1 + LG((n + 1) / 2);
}

void Solve(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  printf("%lld %lld\n", 1ll * n * m * k - 1, LG(n) + LG(m) + LG(k));
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: ", k);
    Solve();
  }
  return 0;
}