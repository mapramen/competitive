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
#define N 200001
#define B 4

vector< vector<int> > edgeNos(N);
int edgeXors[N], edgeWeights[N], dp[N][B], c[N][B];
vector< pii > v{{0, 0}, {0, 0}, {0, 1}, {0, 3}, {1, 0}, {2, 3}, {3, 0}, {3, 2}, {3, 3}, {3, 3}};

ll DFS(int i, int p){
  ll ans = 0;
  ll ansx = 0;

  for(int edgeNo : edgeNos[i]){
    int j = edgeXors[edgeNo] ^ i;
    if(j == p){
      continue;
    }

    for(int k = 0; k < B; ++k){
      c[i][k] = 0;
    }

    ans += DFS(j, i);

    for(int a = edgeWeights[edgeNo], b = 0; b < 2; ++b){
      c[i][2 * a + b] = (a == b) + dp[j][2 * a + b] + (a != b) * dp[j][2 * b + b];
    }

    for(auto q : v){
      int x, y;
      tie(x, y) = q;
      if(dp[i][x] == 0 || c[i][y] == 0){
        continue;
      }

      ans += (1ll * dp[i][x] * c[i][y]);
      ansx += (1ll * dp[i][x] * c[i][y]);
    }

    for(int k = 0; k < B; ++k){
      dp[i][k] += c[i][k];
      ans += (1 + (k == 0 || k == 3)) * c[i][k];
      ansx += 2 * c[i][k];
    }
  }

  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int x = 1; x < n; ++x){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    
    edgeXors[x] = (i ^ j);
    edgeWeights[x] = k;
    edgeNos[i].push_back(x);
    edgeNos[j].push_back(x);
  }

  printf("%lld\n", DFS(1, 0));

  return 0;
}