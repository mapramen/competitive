#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiii tuple< int, int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define M 32
#define N 501

int dp[N][N];

void Initialise(){
  for(int x = 0; x < M; ++x){
    for(int y = 0; y < M; ++y){
      for(int r = N - 1; r >= x; --r){
        for(int b = N - 1; b >= y; --b){
          if(x + y == 0 || r + b == 0){
            continue;
          }
          dp[r][b] = max(dp[r][b], 1 + dp[r - x][b - y]);
        }
      }
    }
  }

  for(int r = 0; r < N; ++r)
    for(int b = 0; b < N; ++b)
      dp[r][b] = max(dp[r][b], max(dp[max(0, r - 1)][b], dp[r][max(0, b - 1)]));
}

int main(){
  int t;

  Initialise();
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    int r, b;
    scanf("%d%d", &r, &b);
    printf("Case #%d: %d\n", k, dp[r][b]);
  }

  return 0;
}
