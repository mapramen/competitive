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
#define N 200001

vector< vector<int> > v(2 * N);
int a[N], d[N];
vector< pii > discounts;

bool Check(int n, int m){
  int s = 0, t = 0;
  
  for(int i = 1; i <= n; ++i){
    s += a[i];
    d[i] = 0;
  }

  for(int i = 1; i <= m; ++i){
    v[i].clear();
  }

  for(pii p : discounts){
    int i, j;
    tie(i, j) = p;
    if(j > m){
      continue;
    }
    d[i] = max(d[i], j);
  }

  for(int i = 1; i <= n; ++i){
    v[d[i]].push_back(i);
  }

  for(int i = 1; i <= m; ++i){
    ++t;
    for(int j : v[i]){
      int x = min(t, a[j]);
      s -= x;
      t -= x;
    }
  }

  return (2 * s <= t);
}

int BinarySearch(int n){
  int x = 0, y = 2 * (N - 1), ans = y;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(n, mid)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return ans;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    discounts.push_back(make_pair(j, i));
  }

  printf("%d\n", BinarySearch(n));

  return 0;
}