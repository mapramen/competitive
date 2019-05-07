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
#define N 100002
#define B 18
#define M (1 << B)

int n, a[N];
ll b[N];
char ch[2];

//----------------------------------------- Segment Tree -----------------------------------------//
int length[M];
ll lazyValue[M], s[M];

void Combine(int k){
  s[k] = s[2 * k + 1] + s[2 * k + 2];
}

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    s[k] = a[l];
  }
  else{
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
    Combine(k);
  }
  length[k] = r - l + 1;
}

void UpdateNode(int k, int x){
  lazyValue[k] += x;
  s[k] += 1ll * x * length[k];
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
  Combine(k);
}

ll Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return 0;
  }

  if(ql <= l && r <= qr){
    return s[k];
  }

  LazyUpdateChildren(k);
  ll ans = Query(2 * k + 1, l, (l + r) / 2, ql, qr) + Query(2 * k + 2, (l + r) / 2 + 1, r, ql, qr);
  Combine(k);

  return ans;
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

set<int> S;

void PreProcess(){
  for(int i = 2; i <= n; ++i){
    b[i] += b[i - 1];
  }

  for(int i = n; i > 0; --i){
    b[i] = a[i] - b[i];
    S.insert(i);
  }
  S.insert(n + 1);
  b[n + 1] = LLONG_MAX;

  BuildSegmentTree(0, 1, n);
}

void Update(int i, int x){
  if(x == 0){
    return;
  }

  b[i] = b[*prev(S.upper_bound(i))];
  S.insert(i);

  ll bi = b[i] + x;
  while(true){
    auto jt = S.lower_bound(i);
    int j = *jt;
    if(bi < b[j]){
      break;
    }
    int k = *next(jt);
    Update(0, 1, n, j, k - 1, bi - b[j]);
    S.erase(j);
  }

  b[i] = bi;
  S.insert(i);
}

ll Query(int i, int j){
  return Query(0, 1, n, i, j);
}

int main(){
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 2; i <= n; ++i){
    scanf("%lld", &b[i]);
  }

  PreProcess();

  int q;
  scanf("%d", &q);
  while(q--){
    int i, j;
    scanf("%s%d%d", ch, &i, &j);
    if(ch[0] == '+'){
      Update(i, j);
    }
    else{
      printf("%lld\n", Query(i, j));
    }
  }

  return 0;
}