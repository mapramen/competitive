#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n;
  scanf("%d", &n);

  ll ans = 0, mul = 1;
  while(n--){
    int x;
    scanf("%d", &x);
    
    mul *= (1 + (x == 0));
    ans += (x == 1);
  }

  return ans * mul;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%lld\n", Solve());
  }

  return 0;
}