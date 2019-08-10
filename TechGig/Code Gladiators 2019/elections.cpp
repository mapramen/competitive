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
#define B 18
#define M (1 << B)

int a[M], b[M];

//----------------------------------------- Segment Tree -----------------------------------------//
int minVal[M], maxVal[M], lazyVal[M], length[M];

void Combine(int k){
  minVal[k] = minVal[2 * k + 1];
  maxVal[k] = maxVal[2 * k + 2];
}

void BuildSegmentTree(int k, int i, int j){
  if(i == j){
    minVal[k] = b[i];
    maxVal[k] = b[i];
  }
  else{
    BuildSegmentTree(2 * k + 1, i, (i + j) / 2);
    BuildSegmentTree(2 * k + 2, (i + j) / 2 + 1, j);
    Combine(k);
  }
  lazyVal[k] = 0;
  length[k] = j - i + 1;
}

void UpdateNode(int k, int val){
  minVal[k] += val;
  maxVal[k] += val;
  lazyVal[k] += val;
}

void LazyUpdateChildren(int k){
  if(lazyVal[k] == 0){
    return ;
  }
  UpdateNode(2 * k + 1, lazyVal[k]);
  UpdateNode(2 * k + 2, lazyVal[k]);
  lazyVal[k] = 0;
}

void Update(int k, int l, int r, int &x){
  if(x == 0 || maxVal[k] == 0){
    return ;
  }

  if(l == r || (minVal[k] > 0 && length[k] <= x)){
    UpdateNode(k, -1);
    x -= length[k];
    return ;
  }

  LazyUpdateChildren(k);
  Update(2 * k + 1, l, (l + r) / 2, x);
  Update(2 * k + 2, (l + r) / 2 + 1, r, x);
  Combine(k);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void GetCounts(int n, int a[]){
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
}

int main(){
  int t;
  scanf("%d", &t);
  
  while(t--){
    int n, m;
    scanf("%d%d", &n, &m);
    
    GetCounts(n, a);
    GetCounts(m, b);
    BuildSegmentTree(0, 1, m);

    ll s = 0;
    for(int i = 1; i <= n; ++i){
      s += a[i];
    }

    for(int j = 1; j <= m; ++j){
      s -= b[j];
    }

    bool valid = s == 0;
    for(int i = n; i > 0 && valid; --i){
      int x = a[i];
      Update(0, 1, m, x);
      valid = (x == 0);
    }

    printf("%s\n", valid ? "YES" : "NO");
  }

  return 0;
}