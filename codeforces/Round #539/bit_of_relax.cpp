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
#define B 20
#define M (1 << B)

int c[2][M];

int main(){
  int n;
  ll ans = 0;

  scanf("%d", &n);
  
  c[0][0] = 1;
  for(int p = 0, i = 1, a, x = 1; i <= n; ++i, x = 1 - x){
    scanf("%d", &a);
    p ^= a;
    ans += c[x][p];
    ++c[x][p];
  }

  printf("%lld\n", ans);
  
  return 0;
}