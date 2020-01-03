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

vector< vector<int> > moves(4);
int a[N], nextStates[4][8], costs[4][8], dpMin[N][4], dpMax[N][4];

void Initialise(int n){
  for(int x = 0; x < 4; ++x){
    for(int y = 0; y < 8; ++y){
      if((x > 0 && y == 0) || x < __builtin_popcount(y)){
        continue;
      }
      moves[x].push_back(y);
    }
  }

  for(int x = 0; x < 4; ++x){
    for(int move = 0; move < 8; ++move){
      nextStates[x][move] = (x | move) / 2;
      costs[x][move] = __builtin_popcount(x | move) - __builtin_popcount(x);
    }
  }

  for(int i = 0; i <= n; ++i){
    for(int x = 0; x < 4; ++x){
      dpMin[i][x] = n;
      dpMax[i][x] = 0;
    }
  }

  dpMin[0][0] = 0, dpMax[0][0] = 0;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ++a[x];
  }

  Initialise(n);

  for(int i = 1; i <= n; ++i){
    a[i] = min(3, a[i]);

    for(int move : moves[a[i]]){
      for(int x = 0; x < 4; ++x){
        int y = nextStates[x][move];
        int cost = costs[x][move];

        dpMin[i][y] = min(dpMin[i][y], dpMin[i - 1][x] + cost);
        dpMax[i][y] = max(dpMax[i][y], dpMax[i - 1][x] + cost);
      }
    }
  }

  int ansMin = INT_MAX, ansMax = INT_MIN;
  for(int x = 0; x < 4; ++x){
    ansMin = min(ansMin, dpMin[n][x]);
    ansMax = max(ansMax, dpMax[n][x]);
  }

  printf("%d %d\n", ansMin, ansMax);

  return 0;
}