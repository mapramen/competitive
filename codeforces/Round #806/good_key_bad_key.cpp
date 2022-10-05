#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define B 30

int a[N];

ll Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = 0, s = 0;
  for(int i = 1; i <= n + 1; ++i){
    ll ansx = s;
    for(int j = i, p = 2; j < min(n + 1, i + B); ++j, p *= 2){
      ansx += (a[j] / p);
    }
    ans = max(ans, ansx);
    s += a[i] - k;
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