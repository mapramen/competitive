#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 3001

int a[N], cnt[N];
ll prefix_sum[N];

ll Calculate(int n, ll k){
  for(int i = 1; i <= n; ++i){
    prefix_sum[i] = prefix_sum[i - 1] + (a[i] != 0 ? a[i] : 0);
    cnt[i] = cnt[i - 1] + (a[i] == 0);
  }

  ll ans = -1;
  for(int i = 0; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      ll min_low = prefix_sum[i] - cnt[i] * k, min_high = prefix_sum[i] + cnt[i] * k;
      ll max_low = prefix_sum[j] - cnt[j] * k, max_high = prefix_sum[j] + cnt[j] * k;

      max_high = min(max_high, (cnt[n] - cnt[j]) * k - (prefix_sum[n] - prefix_sum[j]));
      max_low = max(max_low, -(cnt[n] - cnt[j]) * k - (prefix_sum[n] - prefix_sum[j]));
      
      if(max_high < max_low){
        continue;
      }

      ll range_low = (prefix_sum[j] - prefix_sum[i]) - (cnt[j] - cnt[i]) * k;
      ll range_high = (prefix_sum[j] - prefix_sum[i]) + (cnt[j] - cnt[i]) * k;

      ans = max(ans, 1 + min(range_high, max_high - min_low));
    }
  }

  return ans;
}

int main(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = Calculate(n, k);

  for(int i = 1; i <= n; ++i){
    a[i] = -a[i];
  }

  ans = max(ans, Calculate(n, k));

  printf("%lld\n", ans);

  return 0;
}