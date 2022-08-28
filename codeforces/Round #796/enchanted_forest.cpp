#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

ll a[N];

ll Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
    a[i] += a[i - 1];
  }

  ll base_ans = 1ll * n * max(0, k - n);
  k = min(k, n);
  base_ans += 1ll * k * (k - 1) / 2;

  ll ans = 0;
  for(int i = k; i <= n; ++i){
    ans = max(ans, a[i] - a[i - k]);
  }

  return base_ans + ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}