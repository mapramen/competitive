#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 3001

int a[N];

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    int k = i + 1;
    for(int j = i + 2; j <= n; ++j){
      for( ; k + 1 < j && a[k] + a[k + 1] <= a[i] + a[j]; ++k);
      ans += 1ll * (a[i] - a[k]) * (a[k] - a[j]);
    }
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