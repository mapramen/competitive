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
#define B 17
#define M (1 << B)

char s[N];
int n, m, A[B][B], a[N], cnt[B];
bool dp[M], mark[B][B][M];

void Mark(int mask, int a, int b){
  if(mark[a][b][mask]){
    return ;
  }

  dp[mask] = true;
  mark[a][b][mask] = true;
  
  for(int k = 0; k < m; ++k){
    if((mask & (1 << k)) == 0 || k == a || k == b){
      continue;
    }
    Mark(mask ^ (1 << k), a, b);
  }
}

int main(){
  scanf("%d%d%s", &n, &m, s);

  for(int i = 0; i < m; ++i){
    for(int j = 0; j < m; ++j){
      scanf("%d", &A[i][j]);
    }
  }

  for(int i = 0; i < n; ++i){
    vector< pii > v;
    for(int j = 0; j < m; ++j){
      if(cnt[j] == 0){
        continue;
      }
      v.push_back(make_pair(a[j], j));
    }
    sort(v.begin(), v.end(), greater< pii >());

    int x = s[i] - 'a', mask = (1 << m) - 1;
    for(pii p : v){
      int y = p.second;
      if(A[x][y] == 0){
        if(x < y){
          Mark(mask, x, y);
        }
        else{
          Mark(mask, y, x);
        }
      }
      if(y != x){
        mask ^= (1 << y);
      }
    }

    a[x] = i;
    ++cnt[x];
  }

  int ans = n;
  dp[(1 << m) - 1] = false;
  for(int mask = (1 << m) - 2; mask > -1; --mask){
    if(dp[mask]){
      continue;
    }

    int ansx = 0;
    bool value = true;

    for(int k = 0; k < m; ++k){
      if((mask & (1 << k)) > 0){
        ansx += cnt[k];
        continue;
      }
      value &= dp[(mask | (1 << k))];
    }
    dp[mask] = value;

    if(!value){
      ans = min(ans, ansx);
    }
  }

  printf("%d\n", ans);

  return 0;
}