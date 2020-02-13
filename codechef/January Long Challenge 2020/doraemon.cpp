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

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector< vector<int> > a(n, vector<int>(m));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  int ans = 0;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      for(int i1 = i, i2 = i, j1 = j, j2 = j; i1 >= 0 && i2 < n && j1 >= 0 && j2 < m; --i1, ++i2, --j1, ++j2){
        if(a[i1][j] != a[i2][j] || a[i][j1] != a[i][j2]){
          break;
        }
        ++ans;
      }
    }
  }

  for(int i = 0; i < n; ++i){
    a[i].clear();
  }
  a.clear();

  return ans;
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}