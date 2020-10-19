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

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 3

vector<int> a;
ll dp[2][B][2][2], inf = 1E18;

int main(){
  int n;

  scanf("%d", &n);

  a.resize(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  int cur = 0;

  for(int i = 0; i < B; ++i){
    for(int j = 0; j < 2; ++j){
      for(int k = 0; k < 2; ++k){
        dp[cur][i][j][k] = -inf;
      }
    }
  }

  dp[cur][(n % 3)][(n == 1)][0] = a[0];
  dp[cur][((n + 1) % 3)][(n == 1)][1] = -a[0];

  for(int y = 1; y < n; ++y){
    int x = a[y];
    int nxt = 1 - cur;

    for(int i = 0; i < B; ++i){
      for(int j = 0; j < 2; ++j){
        for(int k = 0; k < 2; ++k){
          dp[nxt][i][j][k] = -inf;
        }
      }
    }

    for(int i = 0; i < B; ++i){
      for(int j = 0; j < 2; ++j){
        for(int k = 0; k < 2; ++k){
          for(int nk = 0; nk < 2; ++nk){
            int ni = (i + (nk != 0)) % B;
            int nj = (j | (k == nk));

            dp[nxt][ni][nj][nk] = max(dp[nxt][ni][nj][nk], dp[cur][i][j][k] + (1 - 2 * nk) * x);
          }
        }
      }
    }

    swap(cur, nxt);
  }

  printf("%lld\n", max(dp[cur][1][1][0], dp[cur][1][1][1]));

  return 0;
}