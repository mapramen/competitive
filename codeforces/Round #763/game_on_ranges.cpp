#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>

void Solve(){
  int n;
  scanf("%d", &n);

  vector<tiii> v(n);
  for(int i = 0; i < n; ++i){
    int l, r;
    scanf("%d%d", &l, &r);
    v[i] = {r - l + 1, l, r};
  }
  sort(v.begin(), v.end());

  for(auto [_, l, r]: v){
    tiii t = {INT_MIN, 0, 0};
    for(auto [len, lx, rx]: v){
      if(lx == l && rx == r){
        continue;
      }

      if(l <= lx && rx <= r){
        t = max(t, {len, lx, rx});
      }
    }

    auto [__, lx, rx] = t;

    int d = lx == l ? rx + 1 : lx - 1;
    d = max(l, d);
    
    printf("%d %d %d\n", l, r, d);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}