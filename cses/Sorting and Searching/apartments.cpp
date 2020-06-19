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
#define N 200001

int a[N], b[N];

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int j = 1; j <= m; ++j){
    scanf("%d", &b[j]);
  }

  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);

  int ans = 0;
  for(int i = 1, j = 1; i <= n && j <= m; ){
    if(b[j] < a[i] - k){
      ++j;
      continue;
    }

    if(b[j] <= a[i] + k){
      ++j;
      ++ans;
    }

    ++i;
  }

  printf("%d\n", ans);

  return 0;
}