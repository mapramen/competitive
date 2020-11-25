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
#define N 101

int a[N][N];

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  bool ans = false;
  for(int k = 2; k <= n + m && !ans; ++k){
    int s = 0;
    for(int x = max(1, k - m), y = k - x; x <= min(n, k - 1); ++x, --y){
      s ^= a[x][y];
    }
    ans = s != 0;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "Ashish" : "Jeel");
  }
  return 0;
}