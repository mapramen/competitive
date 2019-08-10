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

int a[2], b[2];

void ReadInput(int n, int a[]){
  while(n--){
    int x;
    scanf("%d", &x);
    ++a[(x % 2)];
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  ReadInput(n, a);
  ReadInput(m, b);

  int ans = min(a[0], b[1]) + min(a[1], b[0]);

  printf("%d\n", ans);
  
  return 0;
}