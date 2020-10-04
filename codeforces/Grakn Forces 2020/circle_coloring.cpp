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
#define N 101

int a[N], b[N], c[N], p[N];

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &c[i]);
  }

  for(int i = 1; i <= n; ++i){
    p[i] = 0;
  }

  for(int i = 1; i <= n; ++i){
    int j = i == 1 ? n : i - 1;
    int k = i == n ? 1 : i + 1;

    if(a[i] != p[j] && a[i] != p[k]){
      p[i] = a[i];
      continue;
    }

    if(b[i] != p[j] && b[i] != p[k]){
      p[i] = b[i];
      continue;
    }

    if(c[i] != p[j] && c[i] != p[k]){
      p[i] = c[i];
      continue;
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", p[i]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}