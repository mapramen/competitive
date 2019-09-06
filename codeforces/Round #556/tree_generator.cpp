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
#define B 19
#define M (1 << B)

const int inf = 1E9;
int a[N];
char s[N];

//----------------------------------------- Segment Tree -----------------------------------------//
int lazyValue[M], value[M], minValue[M], maxValue[M], leftAns[M], rightAns[M], ans[M];

void UpdateNode(int k, int x){
  value[k] += x;
  lazyValue[k] += x;
  
  minValue[k] += x;
  maxValue[k] += x;
  
  leftAns[k] -= x;
  rightAns[k] -= x;
}

void Combine(int k){
  int k1 = 2 * k + 1, k2 = 2 * k + 2;

  minValue[k] = min(minValue[k1], minValue[k2]);
  maxValue[k] = max(maxValue[k1], maxValue[k2]);

  leftAns[k] = max(maxValue[k2] - 2 * minValue[k1], max(leftAns[k1], leftAns[k2]));
  rightAns[k] = max(maxValue[k1] - 2 * minValue[k2], max(rightAns[k1], rightAns[k2]));
  ans[k] = max(max(ans[k1], ans[k2]), max(maxValue[k1] + leftAns[k2], rightAns[k1] + maxValue[k2]));
}

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    UpdateNode(k, a[l]);
  }
  else{
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
    Combine(k);
  }
}

void LazyUpdateChildren(int k){
  if(lazyValue[k] == 0){
    return ;
  }

  UpdateNode(2 * k + 1, lazyValue[k]);
  UpdateNode(2 * k + 2, lazyValue[k]);
  lazyValue[k] = 0;
}

void Update(int k, int l, int r, int ql, int qr, int x){
  if(qr < l || r < ql || r < l){
    return ;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, x);
    return ;
  }

  LazyUpdateChildren(k);
  Update(2 * k + 1, l, (l + r) / 2, ql, qr, x);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, x);
  Combine(k);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void PreProcess(int n){
  for(int i = 2; i < n; ++i){
    a[i] = (s[i - 2] == '(' ? 1 : -1);
  }

  for(int i = 1; i <= n; ++i){
    a[i] += a[i - 1];
  }

  BuildSegmentTree(0, 1, n);
  for(int i = 2; i < n; ++i){
    a[i] = (s[i - 2] == '(' ? 1 : -1);
  }

  printf("%d\n", ans[0]);
}

int inline Update(int n, int i, int j){
  ++i, ++j;
  if(a[i] == a[j]){
    return ans[0];
  }

  if(i > j){
    swap(i, j);
  }

  swap(a[i], a[j]);
  Update(0, 1, n, i, j - 1, a[i] - a[j]);
  return ans[0];
}

int main(){
  int n, q;
  
  scanf("%d%d%s", &n, &q, s);
  n *= 2;
  PreProcess(n);

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    printf("%d\n", Update(n, i, j));
  }

  return 0;
}