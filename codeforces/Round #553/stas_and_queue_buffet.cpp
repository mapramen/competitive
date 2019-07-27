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

int a[N], b[N];

int main(){
  int n;
  vector< pii > v;
  
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i], &b[i]);
    v.push_back(make_pair(b[i] - a[i], i));
  }

  sort(v.begin(), v.end());

  ll ans = 0, j = 1;
  for(auto p : v){
    int i = p.second;
    ans += (a[i] * (j - 1) + b[i] * (n - j));
    ++j;
  }

  printf("%lld\n", ans);
  
  return 0;
}