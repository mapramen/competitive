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

int a[N], ans[N], x = INT_MIN, y = INT_MAX;

void AddToIncreasingSequence(int i){
  ans[i] = 0;
  x = a[i];
}

void AddToDecreasingSequence(int i){
  ans[i] = 1;
  y = a[i];
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    int c = (x < a[i]) + (y > a[i]);

    if(c == 0){
      printf("NO\n");
      return 0;
    }

    if((c == 2 && a[i] < a[i + 1]) || (c == 1 && x < a[i])){
      AddToIncreasingSequence(i);
    }
    else{
      AddToDecreasingSequence(i);
    }
  }

  printf("YES\n");
  for(int i = 1; i <= n; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}