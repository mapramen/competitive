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
#define M 101
#define MOD 1000000007

int f[M], dp[2][M];
string s;

int ComputeFailure(int i, char c){
  for( ; i != 0 && s[i] != c; i = f[i]);
  return i + (s[i] == c);
}

int NextState(int i, char c){
  return i == s.size() ? i : ComputeFailure(i, c);
}

int main(){
  int n;
  cin >> n >> s;

  int m = s.size();
  
  for(int i = 2; i <= n; ++i){
    f[i] = ComputeFailure(f[i - 1], s[i - 1]);
  }

  int prv = 0;
  dp[prv][0] = 1;

  for(int x = 1; x <= n; ++x){
    int cur = 1 - prv;

    for(int j = 0; j <= m; ++j){
      dp[cur][j] = 0;
    }

    for(int i = 0; i <= m; ++i){
      for(char c = 'A'; c <= 'Z'; ++c){
        int j = NextState(i, c);
        dp[cur][j] = (dp[cur][j] + dp[prv][i]) % MOD;
      }
    }

    swap(prv, cur);
  }

  cout << dp[prv][m] << '\n';
  
  return 0;
}