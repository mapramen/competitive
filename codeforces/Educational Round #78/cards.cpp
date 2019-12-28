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
#define MOD 998244353
#define K 5001

ll dp[K];

int ModExp(int a, int n){
  int ans = 1;
  for( ; n; n /= 2){
    if(n % 2){
      ans = (1ll * a * ans) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans % MOD;
}

int ModInv(int a){
  return ModExp(a, MOD - 2);
}

int main(){
  int n, m, k;

  cin >> n >> m >> k;

  for(int i = 0; i <= k; ++i){
    for(int j = i; j > 0; --j){
      dp[j] = (1ll * j * dp[j] + 1ll * (n - j + 1) * dp[j - 1]) % MOD;
    }
    dp[0] = (i == 0);
  }

  int ans = 0, inv_m = ModInv(m);
  for(int i = k; i > -1; --i){
    ans = (dp[i] + 1ll * inv_m * ans) % MOD;
  }

  cout << ans << '\n';
  
  return 0;
}