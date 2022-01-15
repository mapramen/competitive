#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<pii> corners{{1, 1}, {1, m}, {n, 1}, {n, m}};

  vector<int> v;
  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= m; ++y){
      int ans = 0;
      for(auto [cx, cy]: corners){
        ans = max(ans, abs(x - cx) + abs(y - cy));
      }
      v.push_back(ans);
    }
  }
  sort(v.begin(), v.end());

  for(int vx: v){
    printf("%d ", vx);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}