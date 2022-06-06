#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n;
  scanf("%d", &n);

  ll ans = 0;

  set<pii> S;
  int cnt = 0;

  while(n--){
    int k;
    scanf("%d", &k);

    while(k--){
      int x;
      scanf("%d", &x);
      S.insert({x, ++cnt});
    }

    ans += (S.rbegin()->first - S.begin()->first);

    S.erase(*S.rbegin());
    S.erase(S.begin());
  }

  printf("%lld\n", ans);

  return 0;
}