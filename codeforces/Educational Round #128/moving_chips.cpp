#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200002
#define MAX_MASKS 64

char s[2][N];
int dp_prefix[4][N], dp_suffix[4][N], dp[MAX_MASKS];

void Initialize(){
  for(int mask = 0; mask < MAX_MASKS; ++mask){
    dp[mask] = __builtin_popcount(mask) < 2 ? 0 : MAX_MASKS;
  }

  vector<vector<int>> moves = {
    {1, 2},
    {0, 3},
    {0, 3, 4},
    {1, 2, 5},
    {4, 5},
    {3, 4}
  };

  for(int iter = 0; iter < 64; ++iter){
    for(int mask = 0; mask < 64; ++mask){
      int& ans = dp[mask];
      for(int i = 0; i < 6; ++i){
        if((mask & (1 << i)) == 0){
          continue;
        }
        for(int j: moves[i]){
          int nmask = (mask ^ (1 << i)) | (1 << j);
          ans = min(ans, 1 + dp[nmask]);
        }
      }
    }
  }
}

int GetMask(int i){
  return 2 * (s[0][i - 1] == '*') + (s[1][i - 1] == '*');
}

void ComputePrefix(int n, int dp[4][N]){
  for(int x = 0; x < 4; ++x){
    for(int i = 0; i <= n + 1; ++i){
      dp[x][i] = 0;
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int z = 0; z < 4; ++z){
      dp[z][i] = 2 * N;
    }

    int y = GetMask(i);
    for(int x = 0; x < 4; ++x){
      int z = x | y;
      dp[z][i] = min(dp[z][i], dp[x][i - 1] + __builtin_popcount(x));
    }

    dp[1][i] = min(dp[1][i], 1 + min(dp[2][i], dp[3][i]));
    dp[2][i] = min(dp[2][i], 1 + min(dp[1][i], dp[3][i]));
  }
}

void ComputeSuffix(int n, int dp[4][N]){
  reverse(s[0], s[0] + n);
  reverse(s[1], s[1] + n);
  
  ComputePrefix(n, dp);

  reverse(s[0], s[0] + n);
  reverse(s[1], s[1] + n);

  for(int k = 0; k < 4; ++k){
    reverse(dp[k] + 1, dp[k] + n + 1);
  }
}

int Calculate(int x, int y, int z){
  int mask = (x * 4 + y) * 4 + z;
  return dp[mask];
}

int Solve(){
  int n;
  scanf("%d", &n);
  scanf("%s%s", s[0], s[1]);

  ComputePrefix(n, dp_prefix);
  ComputeSuffix(n, dp_suffix);

  int ans = 2 * n;
  for(int i = 1; i <= n; ++i){
    int y = GetMask(i);
    for(int x = 0; x < 4; ++x){
      for(int z = 0; z < 4; ++z){
        ans = min(ans, dp_prefix[x][i - 1] + dp_suffix[z][i + 1] + Calculate(x, y, z));
      }
    }
  }

  return ans;
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}