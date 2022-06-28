#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define ht tuple<int,int,int>
#define vt tuple<int,int,int,int>
#define N 100001

ordered_set S;
int ans[N], max_y[N];

int GetCount(int x){
  return S.order_of_key(x + 1);
}

int GetCount(int l, int r){
  return GetCount(r) - GetCount(l - 1);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x < N; ++x){
    max_y[x] = -1;
  }

  vector<ht> horizontal_events;
  vector<vt> vertical_events;

  for(int h = 1; h <= n; ++h){
    int l, r;
    scanf("%d%d", &l, &r);

    vertical_events.push_back({l, max_y[l] + 1, h, h});
    vertical_events.push_back({r, max_y[r] + 1, h, h});
    max_y[l] = h, max_y[r] = h;

    if(r - l == 1){
      continue;
    }

    horizontal_events.push_back({l + 1, h, 1});
    horizontal_events.push_back({r, h, -1});
  }

  sort(horizontal_events.begin(), horizontal_events.end(), greater<ht>());
  sort(vertical_events.begin(), vertical_events.end());

  for(vt& vertical_event: vertical_events){
    int xv, yv1, yv2, i;
    tie(xv, yv1, yv2, i) = vertical_event;

    while(!horizontal_events.empty()){
      int xh, yh, val;
      tie(xh, yh, val) = horizontal_events.back();

      if(xh > xv){
        break;
      }

      horizontal_events.pop_back();

      if(val == 1){
        S.insert(yh);
      }
      else{
        S.erase(yh);
      }
    }

    ans[i] += GetCount(yv1, yv2);
  }

  for(int i = 1; i <= n; ++i){
    printf("%d\n", ans[i]);
  }
  
  return 0;
}