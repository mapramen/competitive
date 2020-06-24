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
#define pli pair<ll,int>
#define N 501

ll inf = 1E18;
ll d[N][N];

int main(){
  int n, m, q;

  scanf("%d%d%d", &n, &m, &q);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      d[i][j] = inf;
    }
    d[i][i] = 0;
  }

  while(m--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    d[i][j] = min(d[i][j], 1ll * k);
    d[j][i] = d[i][j];
  }

  for(int k = 1; k <= n; ++k){
    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= n; ++j){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      if(d[i][j] == inf){
        d[i][j] = -1;
      }
    }
  }

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    printf("%lld\n", d[i][j]);
  }

  return 0;
}