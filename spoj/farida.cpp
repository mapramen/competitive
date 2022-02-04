#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n;
  scanf("%d", &n);

  ll ans = 0, skipAns = 0;
  while(n--){
    int x;
    scanf("%d", &x);

    ll newAns = x + skipAns;
    
    skipAns = max(skipAns, ans);
    ans = newAns;
  }

  return max(ans, skipAns);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %lld\n", k, Solve());
  }
  return 0;
}