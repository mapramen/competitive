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

  for(int i = 1; i <= n; ++i){
    int ans = N;
    for(int x: v){
      if(x > i){
        break;
      }
      ans = min(ans, dp[i - x]);
    }
    dp[i] = 1 + ans;
  }

  printf("%d\n", dp[n] >= N ? -1 : dp[n]);
  
  return 0;
}