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
#define N 1000001

vector<vector<int>> divisors(N);
int dp[N], ans[N];

void Initialise(){
  for(int i = 2; i < N; ++i){
    for(int j = i; j < N; j += i){
      divisors[j].push_back(i);
    }
  }

  for(int i = 2; i < N; ++i){
    int dpx = 0, ansx = 0;
    for(int d: divisors[i]){
      int x = dp[(i / d) - 1];
      dpx = max(dpx, x);
      if(d != 2){
        ansx = max(ansx, x);
      }
    }
    dp[i] = 1 + dpx;
    ans[i] = 1 + ansx;
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return ans[n];
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }

  return 0;
}