#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n;
  scanf("%d", &n);

  ll s = 0, ans = 0;
  while(n--){
    int x;
    scanf("%d", &x);

    s += x;
    ans = min(ans, s);
  }

  return 1 - ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Scenario #%d: %lld\n", k, Solve());
  }
  return 0;
}