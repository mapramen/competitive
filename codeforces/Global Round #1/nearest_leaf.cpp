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
#define tiii tuple< int, int, int >
#define N 500001
#define B 20
#define M (1 << B)

vector< vector< pii > > adj(N);
vector< vector< tiii > > queries(N);
int n, startTime[N], finishTime[N];
bool isLeaf[N];
ll d[N], ans[N];
const ll inf = 2E18;

//----------------------------------------- Segment Tree -----------------------------------------//
ll lazyValue[M], value[M];

void Combine(int k){
  value[k] = min(value[2 * k + 1], value[2 * k + 2]);
}

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    value[k] = isLeaf[l] ? d[l] : inf;
  }
  else{
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
    Combine(k);
  }
  lazyValue[k] = 0;
}

void UpdateNode(int k, ll x){
  lazyValue[k] += x;
  value[k] += x;
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
    UpdateNode(k, 1ll * x);
    return ;
  }

  LazyUpdateChildren(k);
  Update(2 * k + 1, l, (l + r) / 2, ql, qr, x);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, x);
  Combine(k);
}

ll Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return inf;
  }

  if(ql <= l && r <= qr){
    return value[k];
  }

  LazyUpdateChildren(k);
  ll ans1 = Query(2 * k + 1, l, (l + r) / 2, ql, qr);
  ll ans2 = Query(2 * k + 2, (l + r) / 2 + 1, r, ql, qr);
  Combine(k);

  return min(ans1, ans2);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void UpdateEulerTree(int root, int w){
  Update(0, 1, n, 1, n, w);
  Update(0, 1, n, startTime[root], finishTime[root], - 2 * w);
}

void DFS(int i){
  for(pii edge : adj[i]){
    int j, w;
    tie(j, w) = edge;
    UpdateEulerTree(j, w);
    DFS(j);
    UpdateEulerTree(j, -w);
  }

  for(tiii query : queries[i]){
    int l, r, x;
    tie(x, l, r) = query;
    ans[x] = Query(0, 1, n, l, r);
  }
}

int main(){
  int q;

  scanf("%d%d", &n, &q);

  for(int j = 2; j <= n; ++j){
    int i, w;
    scanf("%d%d", &i, &w);
    d[j] = d[i] + w;
    adj[i].push_back(make_pair(j, w));
  }

  for(int x = 1; x <= q; ++x){
    int i, l, r;
    scanf("%d%d%d", &i, &l, &r);
    queries[i].push_back(make_tuple(x, l, r));
  }

  for(int i = n; i > 0; --i){
    startTime[i] = i, finishTime[i] = i;
    for(pii edge : adj[i]){
      int j, w;
      tie(j, w) = edge;
      finishTime[i] = max(finishTime[i], finishTime[j]);
    }
    isLeaf[i] = (finishTime[i] == i);
  }

  BuildSegmentTree(0, 1, n);
  DFS(1);

  for(int x = 1; x <= q; ++x){
    printf("%lld\n", ans[x]);
  }

  return 0;
}