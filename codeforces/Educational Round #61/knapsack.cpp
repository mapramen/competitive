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
#define B 8
#define N 840
#define M 15000

ll c[M];
bitset<M> dp;

int main(){
  ll w, s = 0;

  cin >> w;
  for(int i = 1; i <= B; ++i){
    cin >> c[i];
  }

  for(int i = 1; i <= B; ++i){
    ll x = N / i;
    ll z = c[i] - min(x - 1, c[i]);
    
    z = x * (z / x);
    
    c[i] -= z;
    s += ((i * z) / N);
  }

  for(int i = 1; 2 * i < M; ++i){
    if(c[i] % 2 == 1){
      c[2 * i] += (c[i] / 2);
      c[i] = 1;
    }
    else{
      int x = max(0ll, c[i] - 2);
      c[2 * i] += (x / 2);
      c[i] -= x;
    }
  }

  dp[0] = 1;
  for(int i = 1; i < M; ++i){
    int k = c[i];
    while(k--){
      dp |= (dp << i);
    }
  }

  ll ans = 0;
  for(int i = 0; i < M && i <= w; ++i){
    if(!dp.test(i)){
      continue;
    }
    ll x = (w - i) / N;
    x = min(x, s);
    ans = max(ans, i + N * x);
  }

  cout << ans << '\n';

  return 0;
}