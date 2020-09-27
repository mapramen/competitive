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
#define N 100001

int a[N], b[N];

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);

  for(int k = 1, j = n; k <= 2; ++k){
    int i = ((k == 1) == (n % 2 == 1)) ? 1 : 2;
    for( ; i <= n; i += 2, --j){
      b[i] = a[j];
    }
  }

  int ans = 0;
  for(int i = 2; i < n; ++i){
    ans += (b[i - 1] > b[i] && b[i] < b[i + 1]);
  }

  printf("%d\n", ans);
  for(int i = 1; i <= n; ++i){
    printf("%d ", b[i]);
  }
  printf("\n");

  return 0;
}