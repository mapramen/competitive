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
#define M 63000
#define MOD 1000000007
#define INV2 500000004

int dp[M];

int main(){
  int n;

  cin >> n;

  if(n % 4 != 0 && n % 4 != 3){
    printf("0\n");
    return 0;
  }

  int s = (n * (n + 1)) / 4;

  dp[0] = 1;
  for(int i = 1, m = 0; i <= n; ++i){
    m = min(m + i, s);
    for(int j = m; j >= i; --j){
      dp[j] = (dp[j] + dp[j - i]) % MOD;
    }
  }

  printf("%lld\n", (1ll * INV2 * dp[s]) % MOD);

  return 0;
}