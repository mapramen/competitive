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
#define N 1000001

int a[N];

int main(){
  int n;

  scanf("%d", &n);

  if(n == 2 || n == 3){
    printf("NO SOLUTION\n");
    return 0;
  }

  for(int i = 1, x = 2; x <= n; x += 2, ++i){
    a[i] = x;
  }

  for(int i = n / 2 + 1, x = 1; x <= n; x += 2, ++i){
    a[i] = x;
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}