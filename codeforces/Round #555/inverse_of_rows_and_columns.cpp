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
#define N 201

int n, m, a[N][N], rows[N], columns[N];

void Solve(bool fixFirstRow){
  bool mixed = false;
  vector<int> v;

  for(int j = 1; j <= m; ++j){
    columns[j] = fixFirstRow ? a[1][j] : 1 - a[n][j];
  }

  for(int i = 1; i <= n; ++i){
    vector<int> c(2);
    
    for(int j = 1; j <= m; ++j){
      c[(a[i][j] ^ columns[j])] = 1;
    }

    rows[i] = c[0] && c[1] ? (a[i][1] ^ columns[1]) : c[!mixed];

    mixed = (mixed || (c[0] && c[1]));

    for(int j = 1; j <= m; ++j){
      v.push_back((a[i][j] ^ rows[i] ^ columns[j]));
    }
  }

  if(!is_sorted(v.begin(), v.end())){
    return ;
  }

  printf("YES\n");
  
  for(int i = 1; i <= n; ++i){
    printf("%d", rows[i]);
  }
  printf("\n");

  for(int j = 1; j <= m; ++j){
    printf("%d", columns[j]);
  }
  printf("\n");

  exit(0);
}

int main(){
  scanf("%d%d", &n, &m);
  
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  Solve(true);
  Solve(false);

  printf("NO\n");
  
  return 0;
}