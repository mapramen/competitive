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

int a[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  map<int,int> M;
  int ans = 0;

  ll s = 0;
  for(int i = 1, j = i; i <= n; ++i){
    for( ; j <= n; ++j){
      ++M[a[j]];
      s += a[j];
      int x = M.rbegin()->first;
      if(1ll * x * (j - i + 1) - s > m){
        if(--M[a[j]] == 0){
          M.erase(a[j]);
        }
        s -= a[j];
        break;
      }
    }
    ans = max(ans, j - i);
    if(--M[a[i]] == 0){
      M.erase(a[i]);
    }
    s -= a[i];
  }

  printf("%d\n", ans);

  return 0;
}