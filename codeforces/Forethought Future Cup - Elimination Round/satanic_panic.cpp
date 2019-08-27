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
#define tdii tuple< double, int, int >
#define N 301
#define M 6
 
int x[N], y[N];
ll dp[M][N][N];
vector< tdii > v;
 
int main(){
  int n;
 
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> x[i] >> y[i];
  }
 
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      if(i == j){
        continue;
      }
      v.push_back(make_tuple(atan2(y[i] - y[j], x[i] - x[j]), i, j));
    }
  }
 
  sort(v.begin(), v.end());
 
  for(int i = 1; i <= n; ++i){
    dp[0][i][i] = 1;
  }
 
  for(tdii p : v){
    double f;
    int i, j;
    tie(f, i, j) = p;
 
    for(int x = 1; x < M; ++x){
      for(int k = 1; k <= n; ++k){
        dp[x][i][k] += dp[x - 1][j][k];
      }
    }
  }
 
  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += dp[M - 1][i][i];
  }
 
  cout << ans << '\n';
  
  return 0;
}