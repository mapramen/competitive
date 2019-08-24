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
#define N 200002

int c[N], s[N], ans = 0, x, y;

void UpdateAns(int i, int j){
  j -= (c[j] == 0);
  i += (c[i] == 0);

  if(i > j){
    return ;
  }

  int ansx = s[j] - s[i - 1];
  if(ansx > ans){
    ans = ansx;
    x = i, y = j;
  }
}

int main(){
  int n;

  scanf("%d", &n);
  while(n--){
    int i;
    scanf("%d", &i);
    ++c[i];
  }

  for(int i = 1; i < N; ++i){
    s[i] = c[i] + s[i - 1];
  }

  for(int i = 1; i < N; ++i){
    UpdateAns(i - 1, i);
  }

  for(int i = N - 1, j = i; i > 0; --i){
    if(c[i] < 2){
      j = i - 1;
      continue;
    }
    UpdateAns(i - 1, j + 1);
  }

  printf("%d\n", ans);
  for(int i = x; i <= y; ++i){
    printf("%d ", i);
    --c[i];
  }

  for(int i = y; i >= x; --i){
    int k = c[i];
    while(k--){
      printf("%d ", i);
    }
  }
  printf("\n");
  
  return 0;
}