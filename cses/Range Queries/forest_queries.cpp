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
#define N 1001

int T[N][N];
char s[N][N];

void Initialise(int n){
  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= n; ++y){
      T[x][y] = T[x][y - 1] + T[x - 1][y] - T[x - 1][y - 1] + (s[x - 1][y - 1] == '*');
    }
  }
}

int Query(int x, int y){
  return T[x][y];
}

int Query(int x1, int y1, int x2, int y2){
  return Query(x2, y2) + Query(x1 - 1, y1 - 1) - Query(x2, y1 - 1) - Query(x1 - 1, y2);
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  Initialise(n);

  while(q--){
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%d\n", Query(x1, y1, x2, y2));
  }

  return 0;
}