#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiiii tuple< int, int, int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define MOD 1000000007

map< tiiiii, ll > dp;

ll Solve(int s, int n, int m, int r, int c){
  if(s < 0 || n < 0 || m < 0 || r < 0 || c < 0 || s > n * m){
    return 0ll;
  }

  if(s == 0){
    return 1ll;
  }

  r = min(r, n), c = min(c, m);

  auto t = MT(s, n, m, r, c);

  if(dp.count(t)){
    return dp[t];
  }

  ll ans = 0;
  for(int nr = 0; nr <= r; ++nr){
    for(int nc = 0; nc <= c; ++nc){
      if(nr * nc > s){
        continue;
      }
      for(int s1 = 0; s1 <= s - nr * nc; ++s1){
        for(int s2 = 0; s2 <= s - nr * nc - s1; ++s2){
          int s3 = s - nr * nc - s1 - s2;
          ll ansx = (Solve(s1, n - nr - 1, nc, nr, nc) * Solve(s2, nr, m - nc - 1, nr, nc)) % MOD;
          ansx = (ansx * Solve(s3, n - nr, m - nc, nr, nc)) % MOD;
          ans = (ans + ansx) % MOD;
        }
      }
    }
  }

  dp[t] = ans;

  return ans;
}

int main(){
  int n, m;

  cin >> n >> m;

  ll ans = 0;

  for(int s = 0; s <= n * m; ++s){
    ans = (ans + Solve(s, n, m, n, m)) % MOD;
  }

  cout << ans << '\n';

  return 0;
}
