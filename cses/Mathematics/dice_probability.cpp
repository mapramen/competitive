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
#define B 6
#define N 101
#define M (B * N)

double dp[M];

int main(){
  int n, a, b;

  cin >> n >> a >> b;

  int m = B * n;

  dp[0] = 1;
  while(n--){
    for(int i = m; i >= 0; --i){
      double ans = 0;
      for(int x = 1, j = i - 1; x <= B && j > -1; ++x, --j){
        ans += dp[j];
      }
      dp[i] = ans / B;
    }
  }

  double ans = 0;
  for(int i = a; i <= b; ++i){
    ans += dp[i];
  }

  printf("%lf\n", ans);
  
  return 0;
}