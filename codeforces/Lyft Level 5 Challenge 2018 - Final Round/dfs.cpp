#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define M (1 << 19)

vector< vector<int> > adj(N);
vector< vector< pii > > v(N);
int start[N], finish[N], timer;

//----------------------------------------- Segment Tree -----------------------------------------//
int val[M], lazyVal[M], cnt[M];

void InitializeSegmentTree(int k, int l, int r){
  cnt[k] = (r - l + 1);
  if(l != r){
    int mid = (l + r) / 2;
    InitializeSegmentTree(2 * k + 1, l, mid);
    InitializeSegmentTree(2 * k + 2, mid + 1, r);
  }
}

void UpdateNode(int k, int x){
  val[k] += x;
  lazyVal[k] += x;
}

void LazyUpdateChildren(int k){
  if(lazyVal[k] == 0){
    return ;
  }
  UpdateNode(2 * k + 1, lazyVal[k]);
  UpdateNode(2 * k + 2, lazyVal[k]);
  lazyVal[k] = 0;
}

void CombineChildrenData(int k){
  int k1 = 2 * k + 1, k2 = 2 * k + 2;
  int maxVal = max(val[k1], val[k2]);
  cnt[k] = 0;

  if(maxVal == val[k1]){
    cnt[k] += cnt[k1];
  }

  if(maxVal == val[k2]){
    cnt[k] += cnt[k2];
  }

  val[k] = maxVal;
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
  CombineChildrenData(k);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

set< pii > S;

void DFS(int i, int p = 0){
  start[i] = ++timer;
  for(auto j : adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
    v[i].PB(MP(finish[j], j));
  }
  finish[i] = timer;
  sort(v[i].begin(), v[i].end());
}

bool IsAncestor(int i, int j){
  return start[i] <= start[j] && finish[j] <= finish[i];
}

int GetX(int i, int j){
  pii p = MP(i, j);
  if(S.count(p)){
    S.erase(p);
    return -1;
  }
  else{
    S.insert(p);
    return 1;
  }
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS(1);
  InitializeSegmentTree(0, 1, n);

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);

    if(start[i] > start[j]){
      swap(i, j);
    }

    int x = GetX(i, j);

    if(IsAncestor(i, j)){
      int t = lower_bound(v[i].begin(), v[i].end(), MP(finish[j], 0)) - v[i].begin();
      int k = v[i][t].second;
      Update(0, 1, n, 1, n, x);
      Update(0, 1, n, start[k], finish[k], -x);
      Update(0, 1, n, start[j], finish[j], x);
    }
    else{
      Update(0, 1, n, start[i], finish[i], x);
      Update(0, 1, n, start[j], finish[j], x);
    }

    int ans = val[0] == S.size() ? cnt[0] : 0;
    printf("%d\n", ans);
  }

  return 0;
}
