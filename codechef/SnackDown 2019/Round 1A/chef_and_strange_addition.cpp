#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 31

ll dp[N][N][N][2];

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    int n;
    for(int i = 0; i < 30; ++i){
      if((c & (1 << i)) > 0){
        n = i + 1;
      }
    }

    int p = __builtin_popcount(a), q = __builtin_popcount(b);

    dp[0][p][q][0] = 1;

    for(int i = 0; i < n; ++i){
      int ctarget = ((c & (1 << i)) > 0);
      for(int x = 0; x <= p; ++x){
        for(int y = 0; y <= q; ++y){
          for(int carry = 0; carry < 2; ++carry){
            if(dp[i][x][y][carry] == 0){
              continue;
            }
            for(int abit = 0; abit <= min(1, x); ++abit){
              for(int bbit = 0; bbit <= min(1, y); ++bbit){
                if((carry ^ abit ^ bbit) != ctarget){
                  continue;
                }
                int nx = x - abit, ny = y - bbit, ncarry = (carry + abit + bbit) / 2;
                dp[i + 1][nx][ny][ncarry] += dp[i][x][y][carry];
              }
            }
          }
        }
      }
    }

    printf("%lld\n", dp[n][0][0][0]);

    for(int i = 0; i <= n; ++i){
      for(int x = 0; x <= p; ++x){
        for(int y = 0; y <= q; ++y){
          for(int carry = 0; carry < 2; ++carry){
            if(dp[i][x][y][carry] == 0){
              continue;
            }
            dp[i][x][y][carry] = 0;
          }
        }
      }
    }
  }

  return 0;
}
