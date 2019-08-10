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
#define N 1001
#define MOD 1000000007

int dp[2 * N][N];
bool taken[2 * N][N];

int main(){
  int n;
  cin >> n;

  for(int i = 1; i <= 2 * n; ++i){
    for(int j = i % 2; j <= i && j < N; j += 2){
      int &val = dp[i][j];
      bool &c = taken[i][j];

      if(j){
        val = (val + dp[i - 1][j - 1]) % MOD;
        c = (c || !taken[i - 1][j - 1]);
      }

      if(j <= i - 2 && j <= N - 2){
        val = (val + dp[i - 1][j + 1]) % MOD;
        c = (c || !taken[i - 1][j + 1]);
      }

      val = (val + c) % MOD;
    }
  }

  cout << dp[2 * n][0] << '\n';

  return 0;
}