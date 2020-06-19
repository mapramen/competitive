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

int a[N];
map<int,int> M;

int GetLastIndex(int x){
  auto it = M.find(x);
  return it == M.end() ? 0 : it->second;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int ans = 0;
  for(int i = 1, ansx = 0; i <= n; ++i){
    int j = GetLastIndex(a[i]);
    ansx = min(1 + ansx, i - j);
    ans = max(ans, ansx);
    M[a[i]] = i;
  }

  printf("%d\n", ans);

  return 0;
}