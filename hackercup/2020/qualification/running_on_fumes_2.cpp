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
#define N 1000002
#define M (1 << 21)

vector<vector<int>> adj(N);
int parent[N], dis[N];
ll c[N], inf = 1E18;
queue<int> Q;

//----------------------------------------- Segment Tree -----------------------------------------//
ll T[M];

void BuildSegmentTree(int k, int l, int r){
  if(l != r){
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
  }
  T[k] = inf;
}

void Update(int k, int l, int r, int i, ll x){
  if(i < l || r < i){
    return;
  }

  if(l == i && r == i){
    T[k] = min(T[k], x);
    return;
  }

  Update(2 * k + 1, l, (l + r) / 2, i, x);
  Update(2 * k + 2, (l + r) / 2 + 1, r, i, x);
  T[k] = min(T[2 * k + 1], T[2 * k + 2]);
}

ll Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return inf;
  }

  if(ql <= l && r <= qr){
    return T[k];
  }

  ll ans1 = Query(2 * k + 1, l, (l + r) / 2, ql, qr);
  ll ans2 = Query(2 * k + 2, (l + r) / 2 + 1, r, ql, qr);

  return min(ans1, ans2);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void ResetQueue(){
  for( ; !Q.empty(); Q.pop());
}

void ResetParent(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = -1;
    dis[i] = 0;
  }
}

void CheckAndPush(int i, int p){
  if(parent[i] != -1){
    return;
  }
  parent[i] = p;
  dis[i] = 1 + dis[p];
  Q.push(i);
}

vector<int> GetPath(int n, int s, int t){
  ResetQueue();
  ResetParent(n);

  CheckAndPush(s, 0);

  while(!Q.empty() && parent[t] == -1){
    int i = Q.front();
    Q.pop();
    for(int j: adj[i]){
      CheckAndPush(j, i);
    }
  }

  vector<int> v;
  for(int i = t; i != 0; i = parent[i]){
    v.push_back(i);
  }
  reverse(v.begin(), v.end());

  ResetQueue();
  ResetParent(n);

  return v;
}

void ComputeAnsX(int n, int m, int i, int v){
  parent[v] = -1;
  CheckAndPush(v, 0);

  while(!Q.empty()){
    int u = Q.front(), d = dis[u];
    Q.pop();

    if(d >= min(m, i + 1)){
      continue;
    }

    for(int w: adj[u]){
      CheckAndPush(w, u);
    }

    Update(0, 0, n, i - d, c[u] + Query(0, 0, n, i - m + d, i));
  }
}

ll ComputeAns(int m, vector<int> &path){
  int n = path.size();

  if(n - 1 <= m){
    return 0ll;
  }

  BuildSegmentTree(0, 0, n);

  for(int v: path){
    parent[v] = 0;
  }

  Update(0, 0, n, 0, 0ll);
  for(int i = 0; i < n; ++i){
    ComputeAnsX(n, m, i, path[i]);
  }

  ll ans = Query(0, 0, n, n - 1, n - 1);

  return ans == inf ? -1 : ans;
}

ll Solve(){
  int n, m, s, t;
  scanf("%d%d%d%d", &n, &m, &s, &t);

  dis[0] = -1;
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }

  for(int j = 1; j <= n; ++j){
    int i;
    ll x;

    scanf("%d%lld", &i, &x);

    c[j] = x == 0 ? inf : x;

    if(i == 0){
      continue;
    }

    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  c[s] = 0, c[t] = 0;
  vector<int> path = GetPath(n, s, t);

  return ComputeAns(m, path);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %lld\n", k, Solve());
  }
  return 0;
}