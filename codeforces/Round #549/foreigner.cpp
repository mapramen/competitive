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
#define M 11

int dp[M][N];
int b[] = {10, 10, 0, 2, 5, 9, 3, 9, 5, 2, 0};

int main(){
  string s;
  cin >> s;

  ll ans = 0;
  for(int n = s.size(), i = 0; i < n; ++i){
    int d = s[i] - '0';
    
    for(int j = d + 1; j < M; ++j){
      int k = (b[j] + d) % M;
      dp[k][i + 1] = (dp[k][i + 1] + dp[j][i]);
    }
    
    if(d){
      ++dp[d][i + 1];
    }

    for(int k = 0; k < M; ++k){
      ans += dp[k][i + 1];
    }
  }

  printf("%lld\n", ans);

  return 0;
}