#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2002

char s[N][N];
int dp[N][N], a[N][N];

int main(){
  int n, k;

  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%s", s[i] + 1);
  }

  for(int i = 2; i <= n; ++i){
    dp[0][i] = N;
    dp[i][0] = N;
  }

  for(int i = 1; i <= n; ++i){
    a[n + 1][i] = N;
    a[i][n + 1] = N;
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      dp[i][j] = (s[i][j] != 'a') + min(dp[i][j - 1], dp[i - 1][j]);
    }
  }

  if(dp[n][n] <= k){
    cout << string(2 * n - 1, 'a') << '\n';
    return 0;
  }

  int ansi = 0, ansj = 0;
  a[0][0] = N;
  for(int l = 1; l < 2 * n && ansi == 0; ++l){
    vector< pii > v;

    for(int i = 1; i <= n; ++i){
      int j = 2 * n - l - i + 1;
      if(j < 0 || j > n){
        continue;
      }

      pii p = MP(s[i][j], min(a[i][j + 1], a[i + 1][j]));
      v.PB(p);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 1; i <= n; ++i){
      int j = 2 * n - l - i + 1;
      if(j < 0 || j > n){
        continue;
      }

      pii p = MP(s[i][j], min(a[i][j + 1], a[i + 1][j]));
      a[i][j] = lower_bound(v.begin(), v.end(), p) - v.begin() + 1;

      if(dp[i][j] == k + 1 && s[i][j] != 'a'){
        if(a[i][j] < a[ansi][ansj]){
          ansi = i, ansj = j;
        }
      }
    }
  }

  string ans = string(ansi + ansj - 2, 'a');

  for(int i = ansi, j = ansj; i <= n && j <= n; ){
    ans.PB(s[i][j]);
    if(a[i + 1][j] <= a[i][j + 1]){
      ++i;
    }
    else{
      ++j;
    }
  }

  cout << ans << '\n';

  return 0;
}
