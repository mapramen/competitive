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
#define N 200001

int a[N], b[N], ans[N];
map<int,int> M;

int main(){
  int n, m;

  scanf("%d%d", &m, &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    b[i] = a[i];
  }

  b[0] = m;
  sort(b, b + n + 1);

  ans[n] = 0;
  for(int i = 0, x = 0; i <= n; x = b[i], ++i){
    M[x] = b[i];
    ans[n] = max(ans[n], b[i] - x);
  }

  for(int i = n - 1; i > 0; --i){
    int x = a[i + 1];
    auto it = prev(M.lower_bound(x));
    it->second = M[x];
    M.erase(x);
    ans[i] = max(ans[i + 1], it->second - it->first);
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}