#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 200001

ll a[N];

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  vector<tiii> ans;

  for(int x = n - 2, y = n - 1, z = n; x > 0; --x){
    ll val = a[y] - a[z];
    if(val < a[x]){
      a[x] = val;
      ans.push_back({x, y, z});
    }
    if(a[x] < a[y]){
      y = x;
    }
  }

  for(int i = 2; i <= n; ++i){
    if(a[i] < a[i - 1]){
      printf("-1\n");
      return;
    }
  }

  printf("%lu\n", ans.size());
  for(auto [x, y, z]: ans){
    printf("%d %d %d\n", x, y, z);
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