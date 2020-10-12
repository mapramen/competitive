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
#define N 101

int a[N][N];

ll Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  ll ans = 0;
  for(int x1 = 1, x2 = n; x1 <= x2; ++x1, --x2){
    for(int y1 = 1, y2 = m; y1 <= y2; ++y1, --y2){
      vector<int> v{a[x1][y1]};
      if(y2 != y1){
        v.push_back(a[x1][y2]);
      }

      if(x2 != x1){
        v.push_back(a[x2][y1]);
        if(y2 != y1){
          v.push_back(a[x2][y2]);
        }
      }

      sort(v.begin(), v.end());

      if(v.size() >= 2){
        for(int x: v){
          ans += abs(v[1] - x);
        }
      }

      v.clear();
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}