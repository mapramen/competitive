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
#define N 400001

pii a[N];

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1, j = 1; i <= n; ++i, j += 2){
    scanf("%d", &a[j].first);
    scanf("%d", &a[j + 1].first);
    a[j].second = 1, a[j + 1].second = -1;
  }

  sort(a + 1, a + 2 * n + 1);

  int ans = 0;
  for(int i = 1, x = 0; i <= 2 * n; ++i){
    x += a[i].second;
    ans = max(ans, x);
  }

  printf("%d\n", ans);
  
  return 0;
}