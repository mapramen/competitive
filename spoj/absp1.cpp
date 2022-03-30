#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n;
  scanf("%d", &n);

  ll s = 0, ans = 0;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    s += x;
    ans += 1ll * i * x - s;
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