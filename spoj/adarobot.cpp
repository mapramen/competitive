#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Calculate(int n){
  ll ans = 0;
  for(int k = 2; n != 0; ++k, n /= 2){
    int f = k * k * k;
    ans += 1ll * f * (n / 2 - n / 4);
  }
  return ans;
}

ll Solve(){
  int n;
  scanf("%d", &n);
  return Calculate(n - n % 2);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}