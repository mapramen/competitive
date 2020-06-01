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
#define N 501

int a[N], b[N], c[N];
bool dp[N][N];

void Reset(){
  for(int i = 0; i < N; ++i){
    c[i] = 0;
  }
}

void Update(int l, int r){
  if(r < l){
    ++c[0], --c[N - 1];
  }

  ++c[l], --c[r + 1];
}

void Initialise(){
  for(int i = 1; i < N; ++i){
    c[i] += c[i - 1];
  }
}

int main(){
  int n, m;

  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    cin >> a[i] >> b[i];
  }

  dp[0][0] = true;
  for(int i = 1; i <= n; ++i){
    Reset();

    for(int j = 0, x = max(1, m - b[i]), y = min(m - 1, a[i]); j <= m; ++j){
      if(!dp[i - 1][j]){
        continue;
      }
      
      Update(j, j);

      if(x <= y){
        Update((j + x) % m, (j + y) % m);
      }
    }

    Initialise();

    for(int j = 0; j <= m; ++j){
      dp[i][j] = c[j] > 0;
    }
  }

  ll x = 0, y = 0;
  for(int i = 1; i <= n; ++i){
    x += a[i], y += b[i];
  }

  ll ans = (x / m) + (y / m);
  for(int j = 0; j <= m; ++j){
    if(!dp[n][j]){
      continue;
    }
    
    ll ansx = ((x - j) / m) + ((y + j) / m);
    ans = max(ans, ansx);
  }

  cout << ans << '\n';

  return 0;
}