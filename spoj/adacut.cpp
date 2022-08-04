#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001

int a[N];

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ans = min(ans, - 1ll * (n - i + 1) * a[i]);
  }

  for(int i = 1; i <= n; ++i){
    ans += a[i];
  }

  printf("%lld\n", ans);

  return 0;
}