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
#define N 1000001
#define B 21
#define M (1 << B)

int n, a[N], ans[N];

//----------------------------------------- Segment Tree -----------------------------------------//
int lazyValue[M], T[M];

void UpdateNode(int k, int x){
  lazyValue[k] += x;
  T[k] += x;
}

void LazyUpdateChildren(int k){
  if(lazyValue[k] == 0){
    return ;
  }

  UpdateNode(2 * k + 1, lazyValue[k]);
  UpdateNode(2 * k + 2, lazyValue[k]);
  lazyValue[k] = 0;
}

int Combine(int k){
  return max(T[2 * k + 1], T[2 * k + 2]);
}

void Update(int k, int l, int r, int ql, int qr, int x){
  if(qr < l || r < ql){
    return ;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, x);
    return ;
  }

  LazyUpdateChildren(k);
  Update(2 * k + 1, l, (l + r) / 2, ql, qr, x);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, x);
  T[k] = Combine(k);
}

int Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return 0;
  }

  if(ql <= l && r <= qr){
    return T[k];
  }

  LazyUpdateChildren(k);
  int ans = max(Query(2 * k + 1, l, (l + r) / 2, ql, qr), Query(2 * k + 2, (l + r) / 2 + 1, r, ql, qr));
  T[k] = Combine(k);

  return ans;
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

stack<int> P, S;

void Update(int i, int x){
  int j = i;
  while(!S.empty() && S.top() < x){
    j = P.top();
    S.pop();
    P.pop();
  }
  P.push(j);
  S.push(x);

  Update(0, 1, n, j, i, 1);
}

int main(){
  int m;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1, j = 1; j <= n; ++i){
    for( ; j <= n && j < i + m; ++j){
      Update(j, a[j]);
    }
    ans[i] = Query(0, 1, n, i, j - 1);
  }

  for(int i = 1, j = m; j <= n; ++i, ++j){
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}