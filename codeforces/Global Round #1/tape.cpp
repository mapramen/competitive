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

int b[N];

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  int ans = b[n] - b[1] + 1;

  for(int i = n; i > 1; --i){
    b[i] = max(0, b[i] - b[i - 1] - 1);
  }
  b[1] = 0;

  sort(b + 1, b + n + 1, greater<int>());

  for(int i = 1; i < k; ++i){
    ans -= b[i];
  }

  printf("%d\n", ans);

  return 0;
}