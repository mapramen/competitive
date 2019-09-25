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
#define N 101
#define B 26

ll dp[N][B];

int main(){
  ll n, m;
  string s;

  cin >> n >> m >> s;

  dp[0][0] = 1;
  for(char c : s){
    int k = c - 'a';
    for(int i = n; i > 0; --i){
      dp[i][k] = 0;
      for(int j = 0; j < B; ++j){
        dp[i][k] = min(m, dp[i][k] + dp[i - 1][j]);
      }
    }
  }

  ll ans = m * n;
  for(int i = n; i > -1 && m > 0; --i){
    for(int j = 0; j < B && m > 0; ++j){
      ll x = min(dp[i][j], m);
      ans -= x * i;
      m -= x;
    }
  }

  if(m){
    ans = -1;
  }

  cout << ans << '\n';

  return 0;
}