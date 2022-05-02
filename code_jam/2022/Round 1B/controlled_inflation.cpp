#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

int a[N], b[N];
ll dp_entry[N], dp_exit[N], inf = 1E18;

ll Solve(){
  int n, m;
  scanf("%d%d", &m, &n);

  for(int i = 1; i <= n; ++i){
    a[i] = 0, dp_exit[i] = 0;
  }

  while(m--){
    for(int i = 1; i <= n; ++i){
      scanf("%d", &b[i]);
    }
    sort(b + 1, b + n + 1);

    for(int i = 1; i <= n; ++i){
      dp_entry[i] = inf;
    }

    for(ll i = 1, j = 1, dpx = inf; i <= n; ++i){
      for( ; j <= n && a[j] <= b[i]; ++j){
        dpx = min(dpx, dp_exit[j] - a[j]);
      }
      dp_entry[i] = min(dp_entry[i], dpx + b[i]);
    }

    for(ll i = n, j = n, dpx = inf; i > 0; --i){
      for( ; j > 0 && a[j] >= b[i]; --j){
        dpx = min(dpx, dp_exit[j] + a[j]);
      }
      dp_entry[i] = min(dp_entry[i], dpx - b[i]);
    }

    ll entire_row_cost = b[n] - b[1];

    for(int i = 1; i <= n; ++i){
      dp_exit[i] = inf;
    }

    dp_exit[1] = dp_entry[n] + entire_row_cost;
    dp_exit[n] = dp_entry[1] + entire_row_cost;

    ll min_prefix_cost = inf, min_suffix_cost = inf;
    for(int i = 1; i <= n; ++i){
      min_prefix_cost = min(min_prefix_cost, dp_entry[i] + b[i] - b[1]);
      min_suffix_cost = min(min_suffix_cost, dp_entry[i] + b[n] - b[i]);
    }

    for(int i = 1; i <= n; ++i){
      dp_exit[i] = min(dp_exit[i], min_prefix_cost + entire_row_cost + b[n] - b[i]);
      dp_exit[i] = min(dp_exit[i], min_suffix_cost + entire_row_cost + b[i] - b[1]);
    }

    for(int i = 1; i <= n; ++i){
      a[i] = b[i];
    }
  }

  return *min_element(dp_exit + 1, dp_exit + n + 1);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %lld\n", k, Solve());
  }
  return 0;
}