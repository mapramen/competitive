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

int c[N];

int main(){
  int n;
  ll ans = 0;
  c[0] = 1;

  scanf("%d", &n);
  for(int i = 1, s = 0; i <= n; ++i){
    int x;
    scanf("%d", &x);
    s = (s + x) % n;
    s = (n + s) % n;
    ans += c[s];
    ++c[s];
  }

  printf("%lld\n", ans);

  return 0;
}