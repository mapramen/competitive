#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define M 5001

char s[N];
vector<vector<int>> dp(N, vector<int>(M, N));

int main(){
  scanf("%s", s);

  dp[0][0] = 0;

  int n = 0;
  for( ; s[n] != '='; ++n);

  for(int i = 1; i <= n; ++i){
    int j = i;
    for( ; j < n && s[j - 1] == '0'; ++j);

    for(int z = 0; j <= n; ++j){
      z = 10 * z + (s[j - 1] - '0');
      if(z >= M){
        break;
      }

      for(int x = 0, y = z; y < M; ++x, ++y){
        dp[j][y] = min(dp[j][y], 1 + dp[i - 1][x]);
      }
    }
  }

  int m = stoi(s + n + 1);
  printf("%d\n", max(0, dp[n][m] - 1));

  return 0;
}