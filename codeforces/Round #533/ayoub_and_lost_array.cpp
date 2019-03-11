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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define B 3
#define MOD 1000000007

ll c[B], dp[N][B];

void UpdateCost(int n, int x){
  int k = n / B;
  for(int i = 0; i < B; ++i){
    c[i] += x * k;
  }
  for(int i = B * k + 1; i <= n; ++i){
    c[(i % B)] += x;
  }
}

int main(){
  int n, l, r;

  cin >> n >> l >> r;
  UpdateCost(r, 1);
  UpdateCost(l - 1, -1);

  dp[0][0] = 1;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < B; ++j){
      for(int k = 0; k < B; ++k){
        int x = (j + k) % B;
        dp[i + 1][x] = (dp[i + 1][x] + dp[i][j] * c[k]) % MOD;
      }
    }
  }

  cout << dp[n][0] << '\n';

  return 0;
}