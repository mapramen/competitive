#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define tiii tuple<int,int,int>
#define N 51

int parent[N];
vector<tiii> edges;
vector<int> X;
vector<ll> Y;

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

bool Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return false;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  return true;
}

ll MST(int n, int x){
  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }

  vector<tiii> new_edges;
  for(auto [i, j, w]: edges){
    new_edges.push_back({abs(w - x), i, j});
  }
  sort(new_edges.begin(), new_edges.end());

  ll s = 0;
  for(auto [w, i, j]: new_edges){
    s += Union(i, j) * w;
  }
  
  new_edges.clear();

  return s;
}

void AddCheckpoint(int x){
  X.push_back(x);
}

ll Query(int x){
  int i = upper_bound(X.begin(), X.end(), x) - X.begin() - 1;

  if(X[i] == x){
    return Y[i];
  }

  int x1 = X[i], x2 = X[i + 1];
  ll y1 = Y[i], y2 = Y[i + 1];

  return ((y2 - y1) / (x2 - x1)) * (x - x1) + y1;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 1; x <= m; ++x){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    edges.push_back({i, j, w});
  }

  int p, k, a, b, c;
  scanf("%d%d%d%d%d", &p, &k, &a, &b, &c);

  AddCheckpoint(0); AddCheckpoint(c - 1);
  for(int i = 0; i < m; ++i){
    int x = get<2>(edges[i]);
    for(int j = i + 1; j < m; ++j){
      int y = get<2>(edges[j]);
      int mid = (x + y) / 2;
      AddCheckpoint(mid), AddCheckpoint(mid + 1);
    }
    AddCheckpoint(x);
  }
  sort(X.begin(), X.end());
  X.erase(unique(X.begin(), X.end()), X.end());

  for(int& x: X){
    Y.push_back(MST(n, x));
  }

  int xq = 0;
  ll ans = 0;
  for(int i = 1; i <= p; ++i){
    scanf("%d", &xq);
    ans ^= Query(xq);
  }

  for(int i = p + 1; i <= k; ++i){
    xq = (1ll * a * xq + b) % c;
    ans ^= Query(xq);
  }

  printf("%lld\n", ans);

  return 0;
}