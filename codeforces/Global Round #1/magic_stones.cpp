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

int a[N], b[N];

void InputArrayAndReduce(int n, int a[]){
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = n; i > 0; --i){
    a[i] -= a[i - 1];
  }

  sort(a + 2, a + n + 1);
}

int main(){
  int n;

  scanf("%d", &n);
  InputArrayAndReduce(n, a);
  InputArrayAndReduce(n, b);

  bool valid = true;
  for(int i = 1; i <= n && valid; ++i){
    valid = a[i] == b[i];
  }

  printf("%s\n", valid ? "Yes" : "No");

  return 0;
}