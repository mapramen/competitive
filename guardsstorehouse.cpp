#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 15
#define M 251
#define MOD 1000000007

char s[M][M];
int dp[2][2][2][(1 << B)];

void Update(int nxt, int x, int y, int z, int val){
  dp[nxt][x][y][z] = (dp[nxt][x][y][z] + val) % MOD;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; ++i)
    scanf("%s", s[i]);

  if(m < n){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < i; ++j){
        swap(s[i][j], s[j][i]);
      }
    }

    swap(n, m);
  }

  int cur = 0;
  dp[cur][0][0][0] = 1;

  for(int j = 0; j < m; ++j){
    for(int i = 0; i < n; ++i, cur = 1 - cur){
      int nxt = 1 - cur;
      char c = s[i][j];
      memset(dp[nxt], 0, sizeof(dp[nxt]));

      if(i == 0){
        for(int y = 0; y < 2; ++y){
          for(int z = 0; z < (1 << n); ++z){
            dp[cur][0][y][z] = (dp[cur][0][y][z] + dp[cur][1][y][z]) % MOD;
            dp[cur][1][y][z] = 0;
          }
        }
      }

      for(int x = 0; x < 2; ++x){
        for(int y = 0; y < 2; ++y){
          for(int z = 0; z < (1 << n); ++z){
            int val = dp[cur][x][y][z];
            int k = ((z & (1 << i)) > 0);

            if(val == 0)
              continue;

            if(c == '.'){
              int znew = (z | (1 << i));
              if(x == 0){
                if(y == 0){
                  Update(nxt, 0, 1 - k, z, val);
                }
                else{
                  if(k != 0){
                    Update(nxt, 0, 1, z, val);
                  }
                }
                Update(nxt, 1, y, znew, val);
              }
              else{
                Update(nxt, x, y, z, val);
                Update(nxt, x, y, znew, val);
              }
            }
            else{
              int znew = (z & ((1 << n) - (1 << i) - 1));
              Update(nxt, 0, y, znew, val);
            }
          }
        }
      }
    }
  }

  int ans = 0;
  for(int x = 0; x < 2; ++x){
    for(int y = 0; y < 2; ++y){
      for(int z = 0; z < (1 << n); ++z){
        ans = (ans + dp[cur][x][y][z]) % MOD;
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
