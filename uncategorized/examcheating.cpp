#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define M 51

int n, p, m, a[2][N + M], c[N + M];

int Solve(){
  int ans = INT_MIN;
  vector< vector< vector< vector<int> > > > dp(n + m + 1);

  for(int i = 0; i <= n + m; i++){
    dp[i].resize(p + 2);
    for(int j = 0; j <= p + 1; j++){
      dp[i][j].resize(m + 1);
      for(int k = 0; k <= m; k++){
        dp[i][j][k].resize(2);

        if(j == 0 && k != 0)
          for(int x = 0; x < 2; x++)
            dp[i][j][k][x] = INT_MIN;
      }
    }
  }

  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= p; j++)
      for(int k = 0; k <= m; k++)
        for(int x = 0; x < 2; x++){
          dp[i + k][j + 1][m - k][1 - x] = max(dp[i + k][j + 1][m - k][1 - x], dp[i][j][k][x] + c[i + k] - c[i]);
          dp[i + k][j + 1][m - k][x] = max(dp[i + k][j + 1][m - k][x], dp[i][j][k][x] + a[x][i + k] - a[x][i]);

          if(k == 0){
            for(int y = 0; y < 2; y++){
              dp[i + 1][j][0][y] = max(dp[i + 1][j][0][y], dp[i][j][k][x]);
              dp[i][j + 1][0][y] = max(dp[i][j + 1][0][y], dp[i][j][k][x]);
            }
          }
          else
            dp[i + 1][j][k - 1][x] = max(dp[i + 1][j][k - 1][x], dp[i][j][k][x] + a[x][i + 1] - a[x][i]);

          ans = max(ans, dp[i][j][k][x]);
        }
        
  return ans;
}

int main(){
  int r, s, ans;

  cin >> n >> p >> m;

  cin >> r;
  while(r--){
    int i;
    cin >> i;
    a[0][i] = 1;
  }

  cin >> s;
  while(s--){
    int i;
    cin >> i;
    a[1][i] = 1;
  }

  for(int i = 1; i <= n + m; i++){
    c[i] = (a[0][i] | a[1][i]);
    a[0][i] += a[0][i - 1];
    a[1][i] += a[1][i - 1];
    c[i] += c[i - 1];
  }

  if(2 * ((n + m - 1) / m) <= p)
    ans = c[n];
  else
    ans = Solve();

  cout << ans << '\n';

  return 0;
}
