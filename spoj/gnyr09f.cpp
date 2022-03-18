#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

int dp[N][N][2];

void Initialise(){
  dp[0][0][0] = 1;
  for(int i = 1; i < N; ++i){
    for(int j = 0; j < i; ++j){
      for(int x = 0; x < 2; ++x){
        for(int y = 0; y < 2; ++y){
          int pj = j - (x & y);
          if(pj < 0){
            continue;
          }
          dp[i][j][x] += dp[i - 1][pj][y];
        }
      }
    }
  }
}

void Solve(){
  int d, n, k;
  scanf("%d%d%d", &d, &n, &k);
  printf("%d %d\n", d, k >= n ? 0 : dp[n][k][0] + dp[n][k][1]);
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  
  return 0;
}