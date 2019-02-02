#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 41

int m, f[N];
map< pii, ll > dp[2][N];
char s[N];

int ComputeFailure(int i, char c){
  while(i > 0 && s[i] != c){
    i = f[i];
  }
  i += (s[i] == c);
  return i;
}

ll Compute(int n, int s, int t){
  dp[0][0].clear();
  dp[0][0][MP(s, t)] = 1;

  for(int i = 1; i <= n; ++i){
    dp[0][i].clear();
    dp[1][i].clear();

    for(int j = 0; j < 2; ++j){
      for(auto p : dp[j][i - 1]){
        int x, y;
        tie(x, y) = p.first;
        ll val = p.second;
        for(char c = '0'; c <= '1'; ++c){
          int nx = ComputeFailure(x, c), ny = ComputeFailure(y, c);
          int nj = (j | (nx == m) | (ny == m));
          if(nx == m){
            nx = 0;
          }
          if(ny == m){
            ny = 0;
          }
          dp[nj][i][MP(nx, ny)] += val;
        }
      }
    }
  }

  ll ans = 0;
  for(int j = 0; j < m; ++j){
    ans += dp[1][n][MP(t, j)];
  }

  return ans;
}

int main(){
  int n;

  scanf("%d%s", &n, s);

  for(int i = 1; s[i] != '\0'; ++i){
    f[i + 1] = ComputeFailure(f[i], s[i]);
  }

  m = strlen(s);

  ll ans = 0;
  for(int j = 0; j < m; ++j){
    ans += Compute(n, 0, j);
  }

  printf("%lld\n", ans);

  return 0;
}
