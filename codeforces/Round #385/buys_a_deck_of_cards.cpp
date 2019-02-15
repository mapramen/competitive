#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define piii pair< pii, int >
#define PB push_back
#define MP make_pair
#define B 16
#define N (1 << B)

int color[B], r[B], b[B], dp[N][2][B * B + 1];

int main(){
  int n, i, j, k, x, ans, ansr, ansb, ansx;

  cin >> n;

  for(i = ansr = ansb = 0; i < n; i++){
    string s;
    cin >> s >> r[i] >> b[i];
    color[i] = (s == "B");

    ansr += max(0, r[i] - n), ansb += max(0, b[i] - n);
    r[i] = min(r[i], n), b[i] = min(b[i], n);
  }

  for(i = 0; i < (1 << n); i++)
    for(k = 0; k < 2; k++)
      for(j = 0; j <= n * n; j++)
        dp[i][k][j] = INT_MAX / 2;

  dp[0][0][0] = dp[0][1][0] = 0;

  for(i = 0; i < (1 << n); i++){
    int rcnt = 0, bcnt = 0;

    for(x = 0; x < n; x++)
      if((i & (1 << x)))
        rcnt += (color[x] == 0), bcnt += color[x];

    for(x = 0; x < n; x++){
      if((i & (1 << x)))
        continue;

      int new_i = (i | (1 << x));

      for(k = 0; k < 2; k++){
        for(j = 0; j <= n * n; j++){
          if(dp[i][k][j] == INT_MAX / 2)
            continue;
            
          ansx = max(0, max(r[x] - (1 - k) * j - rcnt, b[x] - k * j - bcnt));

          int new_r = (1 - k) * j + ansx - max(0, r[x] - rcnt);
          int new_b = k * j + ansx - max(0, b[x] - bcnt);

          if(new_r == 0)
            dp[new_i][1][new_b] = min(dp[new_i][1][new_b], dp[i][k][j] + ansx);

          if(new_b == 0)
            dp[new_i][0][new_r] = min(dp[new_i][0][new_r], dp[i][k][j] + ansx);
        }
      }
    }
  }

  for(i = (1 << n) - 1, k = 0, ans = INT_MAX; k < 2; k++){
    for(j = 0; j <= n * n; j++){
      int new_ansr = max(0, ansr - (1 - k) * j);
      int new_ansb = max(0, ansb - k * j);

      ansx = n + dp[i][k][j] + max(new_ansr, new_ansb);
      ans = min(ans, ansx);
    }
  }

  cout << ans << '\n';

  return 0;
}
