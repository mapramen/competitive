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
#define N 2001
#define M 1000000

int a[N];

int main(){
  int k, n, m, s;
  bool found = false;

  cin >> k;

  for(n = 1; n < N && !found; ++n){
    s = k + n;
    for(m = 1; m < n && !found; ++m){
      if(s % (n - m) != 0){
        continue;
      }
      int x = s / (n - m);
      if(x <= m * M){
        found = true;
        break;
      }
    }
    if(found){
      break;
    }
  }

  s = (k + n) / (n - m);

  for(int i = n, j = 0; j < m; --i, ++j){
    a[i] = min(M, s);
    s -= a[i];
  }

  a[n - m] = -1;

  printf("%d\n", n);
  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}