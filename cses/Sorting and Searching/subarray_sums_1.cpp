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

int a[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int ans = 0;
  for(int i = 1, j = 1, s = 0; i <= n; ++i){
    for(j = max(i, j), s = max(0, s); j <= n && s + a[j] <= m; ++j){
      s += a[j];
    }

    ans += (s == m);
    s -= a[i];
  }

  printf("%d\n", ans);

  return 0;
}