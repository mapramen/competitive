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

int main(){
  int n, m, k;
  vector< pii > v;

  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1, x; i <= n; ++i){
    scanf("%d", &x);
    v.push_back(make_pair(x, i - 1));
  }

  sort(v.begin(), v.end(), greater< pii >());

  vector<int> a(n);
  ll ans = 0;
  for(int i = 0; i < k * m; ++i){
    ans += v[i].first;
    a[v[i].second] = 1;
  }

  --k;

  printf("%lld\n", ans);
  for(int i = 0, c = 0; i < n && k > 0; ++i){
    c += a[i];
    if(c == m){
      printf("%d ", i + 1);
      --k;
      c = 0;
    }
  }
  printf("\n");

  return 0;
}