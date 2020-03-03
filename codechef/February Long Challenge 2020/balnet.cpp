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
#define N 1000000

pii a[N];
int p[N], b[N][4];
bool c[N];
char s[N + 1];

void SelfAssign(int i){
  p[i] = i;
}

void Pair(int i, int j){
  p[i] = j, p[j] = i;
}

void Solve(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; i += 2){
    Pair(i, i + 1);
  }

  if(n % 2 == 1){
    SelfAssign(n - 1);
  }

  for(int i = 0; i < m; ++i){
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;

    if(p[y] == y){
      swap(x, y);
    }

    b[i][0] = x, b[i][1] = p[x], b[i][2] = y, b[i][3] = p[y];

    if(p[x] == x){
      SelfAssign(p[y]);
    }
    else if(p[x] != y){
      Pair(p[x], p[y]);
    }

    Pair(x, y);
    a[i] = make_pair(x, y);
  }

  for(int i = 0; i < n; ++i){
    c[i] = (i <= p[i]);
  }

  for(int i = m - 1; i > -1; --i){
    int x, y;
    tie(x, y) = a[i];
    Pair(b[i][0], b[i][1]), Pair(b[i][2], b[i][3]);

    s[i] = (c[x] ^ (x > y)) ? '^' : 'v';

    if(p[x] == x){
      c[x] = 1, c[y] = 0;
    }
    else if(p[x] != y){
      c[x] = c[p[y]];
      c[y] = c[p[x]];
    }
  }

  s[m] = '\0';

  printf("%s\n", s);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}