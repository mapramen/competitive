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
#define N 1000002

int a[N], leftEnd[N], rightEnd[N], c[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    rightEnd[a[i]] = i;
  }

  for(int i = n; i > 0; --i){
    leftEnd[a[i]] = i;
  }

  c[n + 1] = m + 1;
  for(int i = m, x = n + 1; i > 0 && rightEnd[i] < x; --i){
    if(leftEnd[i]){
      x = leftEnd[i];
    }
    c[x] = i;
  }

  for(int i = n; i > -1; --i){
    if(c[i] == 0){
      c[i] = c[i + 1];
    }
  }

  ll ans = 0;
  for(int i = 1, x = 0; i <= m; ++i){
    int j = max(i, c[x + 1]);
    ans += (m + 1 - j + (j != i));

    if(leftEnd[i] != 0 && leftEnd[i] < x){
      break;
    }
    
    if(rightEnd[i]){
      x = rightEnd[i];
    }
  }

  printf("%lld\n", ans);

  return 0;
}