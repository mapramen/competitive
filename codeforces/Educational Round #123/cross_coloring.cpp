#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 998244353

int Solve(){
  int n, m, k, q;
  scanf("%d%d%d%d", &n, &m, &k, &q);

  vector<pii> a;
  while(q--){
    int x, y;
    scanf("%d%d", &x, &y);
    a.push_back({x, y});
  }
  reverse(a.begin(), a.end());

  int ans = 1;
  set<int> rows, columns;
  for(auto [x, y]: a){
    if(rows.size() == n || columns.size() == m || (rows.count(x) > 0 && columns.count(y) > 0)){
      continue;
    }

    ans = (1ll * k * ans) % MOD;
    rows.insert(x), columns.insert(y);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}