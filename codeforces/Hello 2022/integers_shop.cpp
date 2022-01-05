#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>

void Solve(){
  int n;
  scanf("%d", &n);

  pii a = {INT_MAX, 0}, b = {INT_MIN, 0};
  map<pii,int> M;

  while(n--){
    int l, r, c;
    scanf("%d%d%d", &l, &r, &c);

    a = min(a, {l, c});
    b = max(b, {r, -c});

    if(M.count({l, r}) == 0){
      M[{l, r}] = INT_MAX;
    }
    M[{l, r}] = min(M[{l, r}], c);

    int ans = a.second - b.second;
    auto it = M.find({a.first, b.first});
    if(it != M.end()){
      ans = min(ans, it->second);
    }

    printf("%d\n", ans);
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