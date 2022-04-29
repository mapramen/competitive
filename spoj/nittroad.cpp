#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 20001
#define M (1 << 16)

char op[2];
vector<int> flip_points[N];
pii edges[N];
int queries[N], parent[N], sz[N];
ll query_ans[N];

vector<int> T[M];

void BuildSegmentTree(int k, int l, int r){
  if(l != r){
    int mid = (l + r) / 2;
    BuildSegmentTree(2 * k + 1, l, mid);
    BuildSegmentTree(2 * k + 2, mid + 1, r);
  }
  T[k].clear();
}

void Update(int k, int l, int r, int ql, int qr, int e){
  if(qr < l || r < ql){
    return;
  }

  if(ql <= l && r <= qr){
    T[k].push_back(e);
    return;
  }

  int mid = (l + r) / 2;
  Update(2 * k + 1, l, mid, ql, qr, e);
  Update(2 * k + 2, mid + 1, r, ql, qr, e);
}

void Reset(int n, int q){
  for(int i = 1; i <= n; ++i){
    flip_points[i].clear();
    flip_points[i].push_back(0);

    parent[i] = i, sz[i] = 1;
  }

  BuildSegmentTree(0, 1, q);
}

int Find(int i){
  return i == parent[i] ? i : Find(parent[i]);
}

void AddRollback(vector<tiii>& rollbacks, int i){
  rollbacks.push_back({i, parent[i], sz[i]});
}

ll Union(int i, int j, vector<tiii>& rollbacks){
  i = Find(i), j = Find(j);

  if(i == j){
    return 0;
  }

  AddRollback(rollbacks, i);
  AddRollback(rollbacks, j);
  
  if(sz[i] < sz[j]){
    swap(i, j);
  }

  parent[j] = i;
  sz[i] += sz[j];

  return 1ll * sz[j] * (sz[i] - sz[j]);
}

void DivideAndConquer(int k, int l, int r, ll ans){
  vector<tiii> rollbacks;

  for(int e: T[k]){
    ans += Union(edges[e].first, edges[e].second, rollbacks);
  }

  if(l == r){
    query_ans[l] = ans;
  }
  else{
    int mid = (l + r) / 2;
    DivideAndConquer(2 * k + 1, l, mid, ans);
    DivideAndConquer(2 * k + 2, mid + 1, r, ans);
  }

  reverse(rollbacks.begin(), rollbacks.end());
  for(tiii& rollback: rollbacks){
    int i = get<0>(rollback), pi = get<1>(rollback), szi = get<2>(rollback);
    parent[i] = pi, sz[i] = szi;
  }
  rollbacks.clear();
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int e = 1; e < n; ++e){
    scanf("%d%d", &edges[e].first, &edges[e].second);
  }

  int q;
  scanf("%d", &q);

  Reset(n, q);

  for(int k = 1; k <= q; ++k){
    scanf("%s", op);

    if(op[0] == 'Q'){
      queries[k] = -1;
    }
    else{
      int e;
      scanf("%d", &e);
      flip_points[e].push_back(k);
      queries[k] = e;
    }
  }

  for(int e = 1; e < n; ++e){
    vector<int>& v = flip_points[e];
    v.push_back(q + 1);

    for(int i = 0; i < v.size() && v[i] <= q; i += 2){
      Update(0, 1, q, v[i], v[i + 1] - 1, e);
    }
  }

  DivideAndConquer(0, 1, q, 0);

  for(int k = 1; k <= q; ++k){
    if(queries[k] != -1){
      continue;
    }
    printf("%lld\n", 1ll * n * (n - 1) / 2 - query_ans[k]);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();

    if(t != 0){
      printf("\n");
    }
  }
  return 0;
}