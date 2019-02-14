#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 17
#define M 11

ll c[N][N], dp[N][N][M][M];

int main(){
  ll t, i;
  string s;

  for(int i = 0; i < N; i++){
    c[i][0] = 1;
    for(int j = 1; j <= i; j++)
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  }

  for(int d = 0; d < N; d++)
    for(int i = 0; i < M; i++)
      dp[0][d][i][0] = 1;

  for(int l = 1; l < N; l++){
    for(int d = 1; d < N; d++){
      for(int i = 1; i < M; i++){
        for(int j = 1; j <= min(l, i); j++){
          ll ans = 0;
          for(int k = 0; k <= i; k++)
            ans += dp[l - j][d - 1][i][k];
          dp[l][d][i][j] = d * c[l - 1][j - 1] * ans;
        }
      }
    }
  }

  int d = N - 1;
  cin >> t >> i;

  if(t == 1)
    s = string("1");
  else{
    for(int l = N - 1; l > 0; l--){
      ll ans = 0;

      for(int k = 0; k < N; k++)
        ans += dp[l][d][i][]
    }
  }


  return 0;
}
