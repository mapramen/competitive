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
#define MOD 998244353
#define INV2 499122177

int main(){
  int n;
  scanf("%d", &n);

  int a = 1, b = 0;
  for(int i = 1; i <= n; ++i){
    b = (a + b) % MOD;
    a = (b - a) % MOD;
  }

  b = (MOD + b) % MOD;
  for(int i = 1; i <= n; ++i){
    b = (1ll * INV2 * b) % MOD;
  }

  printf("%d\n", b);

  return 0;
}