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
#define N 100001

double dp[N], g[N];
int o[N], r[N];

void Compute(double p){
  p = 1 - p;

  dp[1] = 1;
  double q = p * p;
  for(int i = 2; i < N; ++i, q *= p){
    double ans = i;
    r[i] = 0;
    for(int j = 1; j < i; ++j){
      double ansx = dp[j] + dp[i - j];
      if(ansx < ans){
        ans = ansx;
        o[i] = j;
      }
    }

    if(ans < 1 + (1 - q) * ans){
      dp[i] = ans;
      r[i] = 1;
    }
    else{
      dp[i] = 1 + (1 - q) * ans;
    }

    int j = i / 2;
    g[i] = 1 + (1 - q) * (dp[j] + dp[i - j]);
    printf("i = %d r = %d o = %d dp = %lf greedy = %lf diff = %lf foo = %lf\n", i, r[i], o[i], dp[i], g[i], g[i] - dp[i], 100.0 * dp[i] / i);
  }
}

int main(){
  Compute(0.02);
  return 0;
}