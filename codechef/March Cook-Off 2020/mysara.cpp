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
#define MOD 1000000007

int Solve(){
  int n, ans = 1;
  scanf("%d", &n);

  for(int x = 0, y; n > 0; --n, x = y){
    scanf("%d", &y);
    if(y < x){
      ans = 0;
    }
    x &= y;
    ans = (1ll * ans * (1 << __builtin_popcount(x))) % MOD;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}