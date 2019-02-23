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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2000
#define MOD 998244353

int c[N][N];

int main(){
  int n, m, k;

  cin >> n >> m >> k;

  c[0][0] = 1;
  for(int i = 1; i < min(n, N); ++i){
    c[i][0] = 1;
    for(int j = 1; j <= i; ++j){
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }

  ll ans = c[n - 1][k];

  ans = (m * ans) % MOD;
  for(int i = 1; i <= k; ++i){
    ans = (ans * (m - 1)) % MOD;
  }

  cout << ans << '\n';
  
  return 0;
}