#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 51
#define B 3

int a[N][B], dp[N][(1 << B)];

int main(){
  int n, m;

  cin >> n >> m;

  for(int i = 0; i <= n; i++)
    for(int j = 0; j < (1 << B); j++)
      a[i][j] = dp[i][j] = n * m;

  for(int x = 1; x <= n; x++){
    string s;
    cin >> s;

    for(int i = 0; i < m; i++){
      int j, k = min(i, m - i);
      if(s[i] >= 'a' && s[i] <= 'z')
        j = 0;
      else if(s[i] >= '0' && s[i] <= '9')
        j = 1;
      else
        j = 2;
      a[x][j] = min(k, a[x][j]);
    }
  }

  dp[0][0] = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j < (1 << B); j++){
      for(int k = 0; k < B; k++){
        if((j & (1 << k)) != 0){
          dp[i][j] = min(dp[i][j], a[i][k] + dp[i - 1][(j ^ (1 << k))]);
        }
      }
      dp[i][j] = min(dp[i][j], dp[i - 1][j]);
    }
  }

  cout << dp[n][(1 << B) - 1] << '\n';

  return 0;
}
