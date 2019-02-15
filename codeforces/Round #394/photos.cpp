#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tlllll tuple<int, int, int, int, int>
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 1002
#define B 27
#define Q 300001

int M[N][N], cnt[B][N][N], a[Q], b[Q], c[Q], d[Q], e[Q];
ll dp[B][N][N];
char s[N];

void Update(int k, int x){
  cnt[k][a[x]][b[x]]++;
  cnt[k][a[x]][d[x] + 1]--;
  cnt[k][c[x] + 1][b[x]]--;
  cnt[k][c[x] + 1][d[x] + 1]++;
}

ll Query(int k, int x){
  return (dp[k][c[x]][d[x]] + dp[k][a[x] - 1][b[x] - 1] - dp[k][a[x] - 1][d[x]] - dp[k][c[x]][b[x] - 1]);
}

int main(){
  int n, m, q;
  char ch[2];
  ll ans = LLONG_MAX;

  scanf("%d%d%d", &n, &m, &q);

  for(int i = 1; i <= n; i++){
    scanf("%s", s);
    for(int j = 1; j <= m; j++)
      M[i][j] = s[j - 1] - 'a' + 1;
  }

  for(int x = 1; x <= q; x++){
    scanf("%d%d%d%d%s", a + x, b + x, c + x, d + x, ch);
    e[x] = ch[0] - 'a' + 1;
    Update(e[x], x);
    Update(0, x);
  }

  for(int k = 0; k < B; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        cnt[k][i][j] += (cnt[k][i][j - 1] + cnt[k][i - 1][j] - cnt[k][i - 1][j - 1]);

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      cnt[M[i][j]][i][j] += (q - cnt[0][i][j]);

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      ll preAns = 0, preTotal = 0;
      for(int k = 1; k < B; k++){
        dp[k][i][j] += preAns;
        preTotal += cnt[k][i][j];
        preAns += preTotal;
      }

      ll sufAns = 0, sufTotal = 0;
      for(int k = B - 1; k > 0; k--){
        dp[k][i][j] += sufAns;
        sufTotal += cnt[k][i][j];
        sufAns += sufTotal;
      }
    }
  }

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      dp[0][i][j] = dp[M[i][j]][i][j];

  for(int k = 0; k < B; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        dp[k][i][j] += (dp[k][i][j - 1] + dp[k][i - 1][j] - dp[k][i - 1][j - 1]);

  for(int x = 1; x <= q; x++){
    ll ansx = - Query(0, x) + Query(e[x], x);
    ans = min(ans, ansx);
  }

  ans += dp[0][n][m];
  cout << ans << '\n';

  return 0;
}
