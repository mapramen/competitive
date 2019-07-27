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
#define N 100001

int a[N];

ll Cost(int n, int i, int j){
  if(i > j){
    swap(i, j);
  }
  return 1ll * i * (n - j + 1);
}

int main(){
  int n;
  ll ans = 0;

  scanf("%d", &n);
  for(int i = 1, x = 0, y; i <= n; ++i, x = y){
    scanf("%d", &y);
    ans += (Cost(n, y, y) - Cost(n, x, y));
  }

  printf("%lld\n", ans);
  
  return 0;
}