#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define B 6

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<tiii> a;
  for(int i = 1; i <= n; ++i){
    int t, cost, value;
    scanf("%d%d%d", &t, &cost, &value);
    a.push_back({value, cost, t});
  }
  sort(a.begin(), a.end());

  int ans = 0;
  for(int i = 0; i < n; ++i){
    int mask = 0, total_cost = 0, total_value = INT_MAX;
    for(int j = i; j < n; ++j){
      int t, cost, value;
      tie(value, cost, t) = a[j];

      if((mask & (1 << t)) != 0){
        continue;
      }

      mask |= (1 << t), total_cost += cost, total_value = min(total_value, value);

      if(__builtin_popcount(mask) == B && total_cost <= m){
        ans = max(ans, total_value);
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}