#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>

void Solve(){
  int n;
  scanf("%d", &n);

  vector<tiii> v;

  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
    v.push_back({a[i], -1, i});
  }

  vector<int> b(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &b[i]);
    v.push_back({b[i], 1, i});
  }

  sort(v.begin(), v.end());

  vector<pii> d(n);
  for(int k = v.size() - 1, s = 0, mx = 0, mn = 0; k != -1; --k){
    auto [x, si, i] = v[k];

    if(si == 1){
      if(s == 0){
        mx = x;
      }
      mn = x;
    }
    else{
      d[i] = {mn - x, mx - x};
    }

    s += si;
  }


  for(pii& p: d){
    printf("%d ", p.first);
  }
  printf("\n");

  for(pii& p: d){
    printf("%d ", p.second);
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