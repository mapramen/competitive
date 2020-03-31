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
#define N 200001
#define B 10
#define MOD 998244353

int ans[N];

int main(){
  int n;

  scanf("%d", &n);

  ans[n] = B;

  ll x = 2 * (B - 1) * B, y = (B - 1) * (B - 1);

  for(int i = n - 1; i > 0; --i){
    ans[i] = (x + (n - i - 1) * y) % MOD;
    x = (x * B) % MOD;
    y = (y * B) % MOD;
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");
  
  return 0;
}