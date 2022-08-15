#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  vector<pii> a(n);
  for(pii& p: a){
    scanf("%d", &p.first);
  }

  for(pii& p: a){
    scanf("%d", &p.second);
  }

  vector<pii> ans;
  for(int i = n - 1; i != 0; --i){
    for(int j = 0; j < i; ++j){
      if(a[j] > a[i]){
        swap(a[i], a[j]);
        ans.push_back({i, j});
      }
    }
  }

  for(int i = 1; i != n; ++i){
    if(a[i].first < a[i - 1].first || a[i].second < a[i - 1].second){
      printf("-1\n");
      return;
    }
  }

  printf("%lu\n", ans.size());
  for(auto [x, y]: ans){
    printf("%d %d\n", x + 1, y + 1);
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