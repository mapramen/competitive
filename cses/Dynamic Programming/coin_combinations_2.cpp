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
#define N 1000001
#define MOD 1000000007

int dp[N];

int main(){
  int n, m;

  scanf("%d%d", &m, &n);

  vector<int> v;
  while(m--){
    int x;
    scanf("%d", &x);
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  dp[0] = 1;
  for(int x: v){
    for(int i = x, j = 0; i <= n; ++i, ++j){
      dp[i] = (dp[i] + dp[j]) % MOD;
    }
  }

  printf("%d\n", dp[n]);
  
  return 0;
}