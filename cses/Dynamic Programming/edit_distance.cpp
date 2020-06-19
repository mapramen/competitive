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

int dp[2][N];

int main(){
  string A, B;

  cin >> A >> B;

  if(A.size() < B.size()){
    swap(A, B);
  }

  int n = A.size(), m = B.size();

  int prv = 0;
  for(int j = 1; j <= m; ++j){
    dp[prv][j] = j;
  }

  for(int i = 1; i <= n; ++i){
    int cur = 1 - prv;

    dp[cur][0] = i;
    for(int j = 1; j <= m; ++j){
      if(A[i - 1] == B[j - 1]){
        dp[cur][j] = dp[prv][j - 1];
      }
      else{
        dp[cur][j] = 1 + min(dp[prv][j - 1], min(dp[prv][j], dp[cur][j - 1]));
      }
    }

    swap(cur, prv);
  }

  printf("%d\n", dp[prv][m]);

  return 0;
}