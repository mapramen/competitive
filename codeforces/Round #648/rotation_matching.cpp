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
#define N 200001

int a[N], b[N], c[N];

void Read(int n, int a[]){
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    a[x] = i;
  }
}

int main(){
  int n;

  scanf("%d", &n);
  Read(n, a);
  Read(n, b);

  for(int i = 1; i <= n; ++i){
    int x = (n + a[i] - b[i]) % n;
    ++c[x];
  }

  int ans = 0;
  for(int i = 0; i < n; ++i){
    ans = max(ans, c[i]);
  }

  printf("%d\n", ans);

  return 0;
}