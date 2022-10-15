#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define M (1 << 18)

vector<vector<int>> V(N);
int parent[N];

int T[M];

void BuildSegmentTree(int k, int l, int r){
  T[k] = INT_MAX;
  if(l != r){
    int mid = (l + r) / 2;
    BuildSegmentTree(2 * k + 1, l, mid);
    BuildSegmentTree(2 * k + 2, mid + 1, r);
  }
}

int Update(int k, int l, int r, int i, int x){
  if(i < l || r < i){
    return T[k];
  }

  if(i == l && r == i){
    T[k] = min(T[k], x);
    return T[k];
  }

  int mid = (l + r) / 2;
  T[k] = max(Update(2 * k + 1, l, mid, i, x), Update(2 * k + 2, mid + 1, r, i, x));
  return T[k];
}

int Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return 0;
  }

  if(ql <= l && r <= qr){
    return T[k];
  }

  int mid = (l + r) / 2;
  return max(Query(2 * k + 1, l, mid, ql, qr), Query(2 * k + 2, mid + 1, r, ql, qr));
}

int Find(int i){
  return i >= N ? 0 : parent[i];
}

void CheckAndUpdate(int n, int k, int i){
  if(Find(i - 1) != Find(i)){
    return;
  }
  Update(0, 1, n, i - 1, k);
}

void Union(int n, int k, int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return;
  }

  if(V[i].size() < V[j].size()){
    swap(i, j);
  }

  for(int x: V[j]){
    parent[x] = i;
    V[i].push_back(x);
  }

  for(int x: V[j]){
    CheckAndUpdate(n, k, x);
    CheckAndUpdate(n, k, x + 1);
  }

  V[j].clear();
}

void Reset(int n){
  BuildSegmentTree(0, 1, n);

  for(int i = 1; i <= n; ++i){
    parent[i] = i;
    V[i].clear();
    V[i].push_back(i);
  }
}

void Solve(){
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  Reset(n);

  for(int k = 1; k <= m; ++k){
    int i, j;
    scanf("%d%d", &i, &j);
    Union(n, k, i, j);
  }

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d ", l == r ? 0 : Query(0, 1, n, l, r - 1));
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}