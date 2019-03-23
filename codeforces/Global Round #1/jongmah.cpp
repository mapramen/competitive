#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 1000001
#define B 3

int c[N + B], dp[2][B][B];
const int inf = 1E9;

void ResetStateValues(int i){
  for(int x = 0; x < B; ++x){
    for(int y = 0; y < B; ++y){
      dp[i][x][y] = -inf;
    }
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  while(n--){
    int i;
    scanf("%d", &i);
    ++c[i];
  }

  int cur = 0;
  ResetStateValues(cur);
  dp[cur][0][0] = 0;

  for(int i = 1; i <= m; ++i, cur = 1 - cur){
    int nxt = 1 - cur;
    ResetStateValues(nxt);

    for(int x = 0; x < B; ++x){
      for(int y = 0; y < B; ++y){
        if(dp[cur][x][y] < 0){
          continue;
        }
        for(int z = 0; z < B; ++z){
          if(x + y + z > c[i] || y + z > c[i + 1] || z > c[i + 2]){
            continue;
          }
          dp[nxt][y][z] = max(dp[nxt][y][z], dp[cur][x][y] + z + (c[i] - x - y - z) / B);
        }
      }
    }
  }

  int ans = 0;
  for(int x = 0; x < B; ++x){
    for(int y = 0; y < B; ++y){
      ans = max(ans, dp[cur][x][y]);
    }
  }

  printf("%d\n", ans);

  return 0;
}