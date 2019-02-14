#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 51
#define L 5001

ll pre[N], suf[N], sum[N], ansx[N], a[L];

int main(){
  int n, m, i, j, k;
  ll dp, ans = LLONG_MIN;

  scanf("%d%d", &n, &m);

  for(int x = 1; x <= n; x++){
    scanf("%d", &k);

    for(i = 1, dp = 0, ansx[x] = LLONG_MIN; i <= k; i++){
      scanf("%lld", &a[i]);
      ansx[x] = max(ansx[x], a[i]);
      sum[x] += a[i];
      dp += a[i];
      dp = max(0ll, dp);
      ansx[x] = (dp > 0) ? max(ansx[x], dp) : ansx[x];
    }

    ll pre_sum = 0;
    for(i = 1, pre[x] = suf[x] = LLONG_MIN; i <= k; i++){
      suf[x] = max(sum[x] - pre_sum, suf[x]);
      pre_sum += a[i];
      pre[x] = max(pre_sum, pre[x]);
    }
  }

  dp = 0;
  while(m--){
    scanf("%d", &i);
    ans = max(max(ans, ansx[i]), dp + pre[i]);
    dp = max(0ll, max(dp + sum[i], suf[i]));
  }

  printf("%lld\n", ans);

  return 0;
}
