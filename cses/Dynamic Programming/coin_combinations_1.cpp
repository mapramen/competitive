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
  for(int i = 1; i <= n; ++i){
    int ans = 0;
    for(int x: v){
      if(x > i){
        break;
      }
      ans = (ans + dp[i - x]) % MOD;
    }
    dp[i] = ans;
  }

  printf("%d\n", dp[n]);
  
  return 0;
}