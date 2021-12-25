#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 15

ll a[N + 1];

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  ll ans = 1, s = 0, m = 0;
  for(int i = 1; i <= n; ++i){
    for( ; a[i] % 2 == 0; a[i] /= 2){
      ans *= 2;
    }
    s += a[i];
    m = max(m, a[i]);
  }

  return (s - m) + ans * m;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%lld\n", Solve());
  }

  return 0;
}