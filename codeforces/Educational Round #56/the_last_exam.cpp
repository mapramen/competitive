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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

ll a[N + 1];

int main(){
  int n;

  scanf("%d", &n);

  a[n + 1] = LLONG_MAX;
  for(int i = 1, j = n; i <= j; ++i, --j){
    ll x;
    scanf("%lld", &x);
    a[j] = min(x, a[j + 1]);
    a[i] = max(a[i - 1], x - a[j]);
    a[j] = x - a[i];
  }

  for(int i = 1; i <= n; ++i){
    printf("%lld ", a[i]);
  }
  printf("\n");

  return 0;
}