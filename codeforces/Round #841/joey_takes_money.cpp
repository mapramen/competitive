#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n;
  scanf("%d", &n);

  ll ans = 1;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ans *= x;
  }

  return 2022 * (ans + n - 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}