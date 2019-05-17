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
#define N 300001

pii a[N];

int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i].second, &a[i].first);
  }

  sort(a + 1, a + n + 1, greater< pii >());

  priority_queue< int, vector<int>, greater<int> > Q;

  ll ans = 0, s = 0;
  for(int i = 1; i <= n; ++i){
    int x = a[i].second;

    if(Q.size() < m){
      Q.push(x);
      s += x;
    }
    else if(Q.top() < x){
      s += (x - Q.top());
      Q.pop();
      Q.push(x);
    }

    ll ansx = a[i].first * s;
    ans = max(ans, ansx);
  }

  printf("%lld\n", ans);

  return 0;
}