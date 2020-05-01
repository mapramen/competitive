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
#define N 200002

int a[N], b[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  while(n--){
    int x;
    scanf("%d", &x);
    ++a[x];
  }

  for(int i = 1; i <= m; ++i){
    scanf("%d", &b[i]);
  }

  vector< vector<int> > ans;
  vector<int> s;

  for(int i = m, j = 0, k = m + 1; i > 0; --i){
    if(a[i] == 0){
      continue;
    }

    if(b[i] > b[k]){
      j = 0;
    }

    for( ; a[i] > 0; ++j){
      if(j >= ans.size()){
        ans.push_back(vector<int>());
      }

      for( ; ans[j].size() < b[i] && a[i] > 0; --a[i]){
        ans[j].push_back(i);
      }
    }

    j = max(0, j - 1);

    k = i;
  }

  printf("%lu\n", ans.size());
  for(auto v : ans){
    printf("%lu ", v.size());
    for(int x : v){
      printf("%d ", x);
    }
    printf("\n");
  }

  return 0;
}