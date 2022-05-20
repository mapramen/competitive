#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  vector<pii> a(n);
  for(pii& p: a){
    scanf("%d%d", &p.first, &p.second);
  }
  sort(a.begin(), a.end());

  set<pii> s;
  vector<pii> v;
  for(int i = 0; i < n; ){
    for(int x = a[i].first; i < n && a[i].first == x; ++i){
      int y = a[i].second;
      
      auto it = s.upper_bound({y, -1});
      if(it != s.begin()){
        it = prev(it);
        s.erase(it);
      }
      
      v.push_back({y, i});
    }
    
    for(pii& p: v){
      s.insert(p);
    }
    v.clear();
  }

  return s.size();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}