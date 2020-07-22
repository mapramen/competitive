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
#define N 1001
#define MOD 1000000007

ll dp[N];

int main(){
  int n;

  cin >> n;

  dp[0] = 1, dp[1] = 1;
  for(int i = 4; i <= n; ++i){
    int ans = ((i + 1) * dp[i - 1] - (i - 2) * dp[i - 2] - (i - 5) * dp[i - 3] + (i - 3) * dp[i - 4]) % MOD;
    dp[i] = (MOD + ans) % MOD;
  }

  cout << dp[n] << '\n';
  
  return 0;
}