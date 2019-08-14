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
#define N 10000001

int a[N], b[N], X, Y;
ll ans = LLONG_MAX;
pii ansP;

void inline UpdateAns(int i, int j, int g){
  ll ansx = (1ll * b[i] * b[j]) / g;
  if(ansx < ans){
    ans = ansx;
    X = i, Y = j;
  }
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  for(int i = 1; i <= n; ++i){
    int x = b[i];
    if(a[x]){
      UpdateAns(a[x], i, x);
    }
    else{
      a[x] = i;
    }
  }

  for(int i = 1; i < N; ++i){
    int x = 0;
    for(int j = i; j < N; j += i){
      if(a[j]){
        if(x){
          UpdateAns(x, a[j], i);
          break;
        }
        else{
          x = a[j];
        }
      }
    }
  }

  printf("%d %d\n", min(X, Y), max(X, Y));

  return 0;
}