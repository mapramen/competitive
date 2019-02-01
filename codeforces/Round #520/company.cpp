#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define LOGN 17
#define B 18

vector< vector<int> > adj(N);
int d[N];

//------------------------------------- LCA -------------------------------------//
int timeIn[N], timeOut[N], timeV[N], indx[N], ind = 1, timer = 1, lcaTable[2 * LOGN][2 * N], lg[2 * N];

void BuildLCASparseTable(int n){
  n = 2 * n - 1;

  for(int i = 2; i <= n; ++i){
    lg[i] = 1 + lg[i / 2];
  }

  for(int k = 1; (1 << k) <= n; ++k){
    for(int i = 1, j = 1 + (1 << (k - 1)), nk = n - (1 << k) + 1; i <= nk; ++i, ++j){
      lcaTable[k][i] = min(lcaTable[k - 1][i], lcaTable[k - 1][j]);
    }
  }
}

int LCA(int x, int y){
  x = indx[x], y = indx[y];
  if(x > y) swap(x, y);
  int k = lg[y - x + 1];
  k = min(lcaTable[k][x], lcaTable[k][y - (1 << k) + 1]);
  return timeV[k];
}
//----------------------------------- LCA Ends -----------------------------------//

//----------------------------------------- Segment Tree -----------------------------------------//
int minVal[(1 << B)], maxVal[(1 << B)];

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    minVal[k] = timeIn[l];
    maxVal[k] = timeIn[l];
  }
  else{
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
    minVal[k] = min(minVal[2 * k + 1], minVal[2 * k + 2]);
    maxVal[k] = max(maxVal[2 * k + 1], maxVal[2 * k + 2]);
  }
}

int Query(int k, int l, int r, int ql, int qr, bool minQuery){
  if(qr < l || r < ql){
    return minQuery == 1 ? INT_MAX : 0;
  }

  if(ql <= l && r <= qr){
    return minQuery == 1 ? minVal[k] : maxVal[k];
  }

  int ans1 = Query(2 * k + 1, l, (l + r) / 2, ql, qr, minQuery);
  int ans2 = Query(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, minQuery);

  return minQuery == 1 ? min(ans1, ans2) : max(ans1, ans2);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int T[LOGN][N];

void DFS(int i, int p){
  timeIn[i] = ++timer;
  timeV[timeIn[i]] = i;
  indx[i] = ind;
  lcaTable[0][ind++] = timeIn[i];
  d[i] = 1 + d[p];

  for(auto k : adj[i]){
    if(k == p)
    continue;
    DFS(k, i);
    lcaTable[0][ind++] = timeIn[i];
  }

  timeOut[i] = timer;
}

void PreProcess(int n){
  d[0] = -1;
  DFS(1, 0);
  BuildLCASparseTable(n);
  BuildSegmentTree(0, 1, n);

  for(int i = 1; i <= n; ++i){
    T[0][i] = i;
  }

  for(int k = 1; (1 << k) <= n; ++k){
    for(int i = 1, j = 1 + (1 << (k - 1)), nk = n - (1 << k) + 1; i <= nk; ++i, ++j){
      T[k][i] = LCA(T[k - 1][i], T[k - 1][j]);
    }
  }
}

int RangeLCA(int i, int j){
  int k = lg[j - i + 1];
  return LCA(T[k][i], T[k][j - (1 << k) + 1]);
}

pii Query(int l, int r, int i){
  int k;
  if(i == l){
    k = RangeLCA(i + 1, r);
  }
  else if(i == r){
    k = RangeLCA(l, i - 1);
  }
  else{
    k = LCA(RangeLCA(l, i - 1), RangeLCA(i + 1, r));
  }
  return MP(d[k], i);
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int j = 2; j <= n; ++j){
    int i;
    scanf("%d", &i);
    adj[i].PB(j);
  }

  PreProcess(n);

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);

    int u = timeV[Query(0, 1, n, l, r, 1)], v = timeV[Query(0, 1, n, l, r, 0)];

    pii ans = max(Query(l, r, u), Query(l, r, v));

    printf("%d %d\n", ans.second, ans.first);
  }

  return 0;
}
