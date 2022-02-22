#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll PushAndCollectArea(vector<pii>& S, int i, int x){
  ll ans = 0;

  int j = i;
  while(!S.empty() && S.back().first >= x){
    j = S.back().second;
    ans = max(ans, 1ll * S.back().first * (i - j));
    S.pop_back();
  }
  S.push_back({x, j});

  return ans;
}

ll Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  ll ans = 0;
  vector<pii> S;

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ans = max(ans, PushAndCollectArea(S, i, x));
  }

  ans = max(ans, PushAndCollectArea(S, n + 1, 0));

  return ans;
}

int main(){
  while(true){
    printf("%lld\n", Solve());
  }
  return 0;
}