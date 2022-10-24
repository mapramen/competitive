#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  map<ll,int> S;
  for(int i = 1; i <= n; ++i){
    ll s = 0;
    for(int j = 1; j <= m; ++j){
      ll x;
      scanf("%lld", &x);
      s += j * x;
    }
    S[s] = i;
  }

  int k = S.rbegin()->second;
  ll cnt = S.rbegin()->first - S.begin()->first;

  printf("%d %lld\n", k, cnt);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}