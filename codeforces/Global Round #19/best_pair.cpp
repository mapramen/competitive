#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  map<int,int> M;
  while(n--){
    int x;
    scanf("%d", &x);
    ++M[x];
  }

  set<pii> bad_pairs;
  while(m--){
    int x, y;
    scanf("%d%d", &x, &y);
    if(x > y){
      swap(x, y);
    }
    bad_pairs.insert({x, y});
  }

  vector<pii> v;
  for(pii p: M){
    v.push_back({p.second, p.first});
  }
  sort(v.begin(), v.end());
  
  vector<pair<int,vector<int>>> V;

  ll ans = 0;
  for(auto [cx, x]: v){
    for(auto& [cy, u]: V){
      for(int k = u.size() - 1; k != -1; --k){
        int y = u[k];
        if(bad_pairs.count({min(x, y), max(x, y)}) != 0){
          continue;
        }
        ans = max(ans, 1ll * (cx + cy) * (x + y));
        break;
      }
    }

    if(V.empty() || V.back().first != cx){
      V.push_back({cx, {}});
    }

    V.back().second.push_back(x);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}