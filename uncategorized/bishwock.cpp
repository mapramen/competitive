#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101
#define M 2
#define B 4

char s[M][N];
int dp[N][(1 << B)];
vector<int> bishwoks{7, 11, 13, 14};

int main(){
  for(int i = 0; i < M; ++i){
    scanf("%s", s[i]);
  }

  int n = strlen(s[0]);

  for(int i = 0; i <= n; ++i){
    for(int curMask = 0; curMask < (1 << B); ++curMask){
      dp[i][curMask] = INT_MIN;
    }
  }

  dp[0][(1 << B) - 1] = 0;

  for(int i = 1; i <= n; ++i){
    int curVerticalMask = 0;
    for(int j = 0; j < M; ++j){
      curVerticalMask += (s[j][i - 1] == 'X') ? (1 << (M + j)) : 0;
    }

    for(int preMask = 0; preMask < (1 << B); ++preMask){
      int curMask = (preMask >> M) + curVerticalMask;
      int curVal = dp[i - 1][preMask];
      for(auto bishwok : bishwoks){
        int nextMask = curMask, nextVal = curVal;
        if((curMask & bishwok) == 0){
          nextMask |= bishwok;
          ++nextVal;
          dp[i][nextMask] = max(dp[i][nextMask], nextVal);
        }
      }
      dp[i][curMask] = max(dp[i][curMask], curVal);
    }
  }

  int ans = 0;
  for(int curMask = 0; curMask < (1 << B); ++curMask){
    ans = max(ans, dp[n][curMask]);
  }

  printf("%d\n", ans);

  return 0;
}
