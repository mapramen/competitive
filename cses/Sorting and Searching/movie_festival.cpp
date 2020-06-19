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

pii a[N];

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i].second, &a[i].first);
  }
  sort(a + 1, a + n + 1);

  int ans = 0;
  for(int i = 1; i <= n; ){
    int j = i + 1, x = a[i].first;
    for( ; j <= n && a[j].second < x; ++j);
    ++ans;
    i = j;
  }

  printf("%d\n", ans);

  return 0;
}