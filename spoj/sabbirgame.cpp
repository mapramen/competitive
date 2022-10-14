#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n;
  scanf("%d", &n);

  ll s = 0, ans = LLONG_MAX;
  while(n--){
    int x;
    scanf("%d", &x);
    s += x;
    ans = min(ans, s);
  }

  ans = 1 - min(1ll, ans);
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