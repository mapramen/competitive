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
  int n, s;

  scanf("%d%d", &n, &s);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);

  int ans = n;
  for(int i = 1, j = n; i <= j; ++i){
    for( ; i < j && a[i] + a[j] > s; --j);
    if(i != j){
      --ans, --j;
    }
  }

  printf("%d\n", ans);

  return 0;
}