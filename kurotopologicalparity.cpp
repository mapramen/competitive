#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiii tuple< int, int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define MOD 1000000007

map< tiiii, ll > dp[2];

int main(){
  int n, k;

  scanf("%d%d", &n, &k);

  int cur = 0;
  dp[cur][MT(0, 0, 0, 0)] = 1;

  for(int i = 1; i <= n; ++i, cur = 1 - cur){
    int j, nxt = 1 - cur;

    scanf("%d", &j);

    dp[nxt].clear();

    for(int p = (j == -1) ? 0 : j, q = (j == -1) ? 1 : j; p <= q; ++p){
      for(auto t : dp[cur]){
        int a, b, c, d;
        ll val = t.second;

        tie(a, b, c, d) = t.first;

        int y = (p == 1) ? b : d;
        int x = a + b + c + d - y;

        val = (val * ((1ll << x) % MOD)) % MOD;

        for(int r = 0; r < 2; ++r){
          ll valx = val;

          if(y){
            valx = (valx * ((1ll << (y - 1)) % MOD)) % MOD;
          }

          if(r == 1 && y == 0)
            valx = 0;

          int ax = a, bx = b, cx = c, dx = d;

          if(p == 0){
            if(r == 0)
              ++bx;
            else
              ++ax;
          }
          else{
            if(r == 0)
              ++dx;
            else
              ++cx;
          }

          auto tx = MT(ax, bx, cx, dx);
          dp[nxt][tx] = (dp[nxt][tx] + valx) % MOD;
        }
      }
    }
  }

  ll ans = 0;
  for(auto t : dp[cur]){
    int a, b, c, d;
    ll val = t.second;
    tie(a, b, c, d) = t.first;

    if((b + d) % 2 == k)
      ans = (ans + val) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}
