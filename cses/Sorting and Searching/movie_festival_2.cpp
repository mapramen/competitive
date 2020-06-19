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

pii a[N];
multiset<int> S;

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i].second, &a[i].first);
  }
  sort(a + 1, a + n + 1);

  for(int i = 1; i <= m; ++i){
    S.insert(0);
  }

  int ans = 0;
  for(int i = 1, j = 0; i <= n; ++i){
    if(a[i].second < *S.begin()){
      continue;
    }

    S.erase(prev(S.upper_bound(a[i].second)));
    S.insert(a[i].first);
    ++ans;
  }

  printf("%d\n", ans);

  return 0;
}