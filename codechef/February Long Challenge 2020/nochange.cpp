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
#define N 1001

int a[N], c[N];

void PrintYes(int n){
  printf("YES ");
  for(int i = 1; i <= n; ++i){
    printf("%d ", c[i]);
  }
  printf("\n");
}

void Solve(){
  int n, m;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    c[i] = 0;
  }

  for(int i = 1; i <= n; ++i){
    if(m % a[i] == 0){
      continue;
    }
    c[i] = (m / a[i]) + 1;
    PrintYes(n);
    return;    
  }

  for(int i = n; i > 1; --i){
    for(int j = i - 1; j > 0; --j){
      if(a[i] % a[j] == 0){
        continue;
      }
      c[i] = 1;
      c[j] = ((m - a[i]) / a[j]) + 1;
      PrintYes(n);
      return;
    }
  }

  printf("NO\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}