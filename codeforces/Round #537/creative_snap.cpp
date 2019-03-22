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

int A, B;
vector<int> v;

int Query(int x){
  return upper_bound(v.begin(), v.end(), x) - v.begin();
}

int Query(int l, int r){
  return Query(r) - Query(l - 1);
}

ll Solve(int l, int r){
  int cnt = Query(l, r);

  if(cnt == 0){
    return 1ll * A;
  }

  if(r - l == 0){
    return 1ll * cnt * B;
  }

  int mid = (l + r) / 2;
  return min(1ll * B * (r - l + 1) * cnt, Solve(l, mid) + Solve(mid + 1, r));
}

int main(){
  int n, m;

  scanf("%d%d%d%d", &n, &m, &A, &B);

  while(m--){
    int x;
    scanf("%d", &x);
    v.push_back(x);
  }
  sort(v.begin(), v.end());

  ll ans = Solve(1, (1 << n));

  printf("%lld\n", ans);

  return 0;
}