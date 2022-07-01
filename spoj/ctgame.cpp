#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

char s[2];

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

ll Compute(vector<int>& a){
  ll n = a.size() - 1, ans = 0;
  vector<pii> S;

  for(int i = 1; i <= n; ++i){
    ans = max(ans, PushAndCollectArea(S, i, a[i]));
  }
  ans = max(ans, PushAndCollectArea(S, n + 1, 0));

  return ans;
}

ll Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  ll ans = 0;

  vector<int> a(m + 1);
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%s", s);
      a[j] = s[0] == 'R' ? 0 : 1 + a[j];
    }
    ans = max(ans, Compute(a));
  }

  return 3 * ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}