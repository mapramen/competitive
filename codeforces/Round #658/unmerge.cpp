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
#define N 2001

bitset<N> dp;
int a[2 * N];

bool Solve(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= 2 * n; ++i){
    scanf("%d", &a[i]);
  }

  dp.reset();
  dp.set(0);

  for(int i = 1, j = 1; i <= 2 * n; i = j){
    for(j = i + 1; j <= 2 * n && a[j] < a[i]; ++j);
    dp |= (dp << (j - i));
  }

  return dp.test(n);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}