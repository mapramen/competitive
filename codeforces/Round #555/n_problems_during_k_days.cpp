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

int a[N];

bool Solve(int n, int m){
  for(int i = 1; i <= n && m > 0; ++i){
    a[i] = i;
    m -= i;
  }

  if(m < 0){
    return false;
  }

  int x = m / n;
  for(int i = 1; i <= n; ++i){
    a[i] += x;
  }

  m %= n;

  for(int i = n; m > 0 && i > 1; --i){
    int x = min(2 * a[i - 1] - a[i], m);
    a[i] += x;
    m -= x;
  }

  if(m){
    return false;
  }

  for(int i = 2; i <= n; ++i){
    if(a[i] <= a[i - 1] || a[i] > 2 * a[i - 1]){
      return false;
    }
  }

  return true;
}

int main(){
  int m, n;

  scanf("%d%d", &m, &n);

  if(Solve(n, m)){
    printf("YES\n");
    for(int i = 1; i <= n; ++i){
      printf("%d ", a[i]);
    }
    printf("\n");
  }
  else{
    printf("NO\n");
  }

  return 0;
}