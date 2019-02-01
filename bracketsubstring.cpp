#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101
#define MOD 1000000007

int a[2 * N], f[2 * N], dp[2][2 * N][N][2 * N];

int ComputeFailure(int i, int j){
  while(i != 0 && a[i] != j){
    i = f[i];
  }
  i += (a[i] == j);
  return i;
}

int main(){
  int m;
  string s;

  cin >> m >> s;

  int n = 2 * m, l = s.size();
  for(int k = 0; k < l; ++k){
    a[k] = s[k] == '(' ? 1 : -1;
  }

  for(int i = 2; i <= l; ++i){
    f[i] = ComputeFailure(f[i - 1], a[i - 1]);
  }

  dp[0][0][0][0] = 1;
  for(int x = 0; x < 2; ++x){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j <= i && j <= m; ++j){
        for(int k = 0; k < l; ++k){
          if(dp[x][i][j][k] == 0){
            continue;
          }

          int val = dp[x][i][j][k];

          for(int y = -1; y < 2; y += 2){
            int ni = i + 1, nj = j + y;

            if(nj < 0 || nj > m){
              continue;
            }

            int nk = ComputeFailure(k, y);
            int nx = (x | (nk == l));
            nk = (nk == l) ? 0 : nk;

            dp[nx][ni][nj][nk] = (dp[nx][ni][nj][nk] + val) % MOD;
          }
        }
      }
    }
  }

  int ans = 0;
  for(int k = 0; k < l; ++k){
    ans = (ans + dp[1][n][0][k]) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}
