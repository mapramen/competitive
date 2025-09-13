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
#define N 5001

int a[N];
double dp[N][N];

void Initialise(){
  dp[2][1] = 1;
  dp[2][2] = 1;

  for(int n = 3; n < N; ++n){
    for(int i = 1; i <= n; ++i){
      double ans = 0;

      if(i > 2){
        ans += (i - 2) * dp[n - 1][i - 1];
      }

      if(i != 1){
        ans += (1 + dp[n - 1][i - 1]);
      }

      if(i != n){
        ans += (1 + dp[n - 1][i]);
      }

      if(i < n - 1){
        ans += (n - i - 1) * dp[n - 1][i];
      }

      ans /= (n - 1);

      dp[n][i] = ans;
    }
  }
}

double Solve(){
  int n;
  scanf("%d", &n);

  double ans = 0;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ans += dp[n][i] * x;
  }

  return ans;
}

int main(){
  int t;
  Initialise();
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %.9lf\n", k, Solve());
  }
  return 0;
}