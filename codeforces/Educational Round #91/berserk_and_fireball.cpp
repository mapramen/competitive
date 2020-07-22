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
#define N 200002

int a[N], b[N], pos[N];
const ll inf = 1E18;

ll SolveSegment(int l, int r, int x, int y, int k){
  if(r == l + 1){
    return 0ll;
  }

  int p = l + 1;
  for(int i = l + 1; i < r; ++i){
    if(a[i] > a[p]){
      p = i;
    }
  }

  int n = r - l - 1;
  ll ans = 1ll * y * (n % k);
  n /= k;
  ll z = min(1ll * x, 1ll * k * y);

  if(a[p] < max(a[l], a[r])){
    return ans + n * z;
  }

  if(n == 0){
    return inf;
  }

  return ans + x + (n - 1) * z;
}

ll Solve(int n, int m, int x, int y, int k){
  if(n < m){
    return -1;
  }

  for(int i = 1; i <= n; ++i){
    pos[a[i]] = i;
  }

  for(int j = 2; j <= m; ++j){
    if(pos[b[j - 1]] > pos[b[j]]){
      return -1;
    }
  }

  for(int i = 1; i <= n; ++i){
    pos[i] = 0;
  }

  pos[0] = 1;
  for(int j = 1; j <= m; ++j){
    pos[b[j]] = 1;
  }

  ll ans = 0;
  for(int i = 1, l = 0; i <= n + 1; ++i){
    if(pos[a[i]] == 0){
      continue;
    }
    int r = i;
    ll ansx = SolveSegment(l, r, x, y, k);
    if(ansx == inf){
      return -1;
    }
    ans += ansx;
    l = r;
  }

  return ans;
}

int main(){
  int n, m, k, x, y;

  scanf("%d%d", &n, &m);
  scanf("%d%d%d", &x, &k, &y);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= m; ++i){
    scanf("%d", &b[i]);
  }

  printf("%lld\n", Solve(n, m, x, y, k));

  return 0;
}