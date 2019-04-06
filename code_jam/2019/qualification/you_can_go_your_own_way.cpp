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

char s[N], t[N];

void Solve(){
  int n;
  scanf("%d%s", &n, s);

  for(int i = 0, j = 0, x = 0, y = 0; i < n; ++i){
    if(x != i || y != i){
      if(x == i - 1 && y == i + 1){
        t[j] = 'S', t[j + 1] = 'E';
      }
      else{
        t[j] = 'E', t[j + 1] = 'S';
      }
    }
    else{
      if(s[j] == 'E'){
        t[j] = 'S', t[j + 1] = 'E';
      }
      else{
        t[j] = 'E', t[j + 1] = 'S';
      }
    }
    for(int k = 0; k < 2; ++k, ++j){
      if(s[j] == 'E'){
        ++y;
      }
      else{
        ++x;
      }
    }
  }

  t[2 * (n - 1)] = '\0';

  printf("%s\n", t);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: ", k);
    Solve();
  }
  return 0;
}