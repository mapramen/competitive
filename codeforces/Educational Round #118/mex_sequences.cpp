#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 500005
#define MOD 998244353 

int a[N];
ll dpMinus[N], dpPlus[N];

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    int x = a[i];

    int dpx = dpMinus[x] + (x == 1);
    if(x > 1){
      dpx = (dpx + dpPlus[x - 2]) % MOD;
    }

    int dpy = dpPlus[x] + (x == 0);
    if(x > 0){
      dpy = (dpy + dpPlus[x - 1]) % MOD;
    }

    int dpz = dpMinus[x + 2];

    dpMinus[x] = (dpMinus[x] + dpx) % MOD;
    dpPlus[x] = (dpPlus[x] + dpy) % MOD;
    dpMinus[x + 2] = (dpMinus[x + 2] + dpz) % MOD;

    ans = (ans + dpx + dpy + dpz) % MOD;
  }

  for(int i = 0; i <= n + 2; ++i){
    dpMinus[i] = 0, dpPlus[i] = 0;
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