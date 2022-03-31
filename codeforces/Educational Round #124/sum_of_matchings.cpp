#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define t4i tuple<int,int,int,int>
#define N 3001

map<t4i,pair<int,ll>> M;
vector<vector<int>> adj(N);
bool visited[N];
vector<int> a;

void DFS(int i){
  if(visited[i]){
    return;
  }

  visited[i] = true;
  a.push_back(i);

  for(int j: adj[i]){
    DFS(j);
  }
}

ll CalculateCount(int n, t4i t, t4i p){
  auto [l1, r1, L1, R1] = t;
  auto [l2, r2, L2, R2] = p;
  
  ll ans = 1ll * (l1 - l2) * (r2 - r1) * (L1 - L2) * (R2 - R1);

  return ans;
}

void Insert(int n, int len, t4i t, t4i p){
  M[t] = max(M[t], {len, CalculateCount(n, t, p)});
}

t4i Update(int n, t4i t, int x){
  auto [l, r, L, R] = t;

  if(x <= n){
    l = min(l, x), r = max(r, x);
  }
  else{
    L = min(L, x), R = max(R, x);
  }

  return {l, r, L, R};
}

int SanitizeLeftLimit(int l, int r, int z, int x){
  return l <= x && x <= r && x != z ? x : l - 1;
}

int SanitizeRightLimit(int l, int r, int z, int x){
  return l <= x && x <= r && x != z ? x : r + 1;
}

int GetLeftLimit(int l, int r, int x, int y, int z){
  x = SanitizeLeftLimit(l, r, z, x), y = SanitizeLeftLimit(l, r, z, y);
  
  if(x > y){
    swap(x, y);
  }

  if(z < x){
    return l - 1;
  }

  if(z != x && z < y){
    return x;
  }

  return y;
}

int GetRightLimit(int l, int r, int x, int y, int z){
  x = SanitizeRightLimit(l, r, z, x), y = SanitizeRightLimit(l, r, z, y);
  if(x > y){
    swap(x, y);
  }

  if(y < z){
    return r + 1;
  }

  if(x < z){
    return y;
  }

  return x;
}

t4i GetLimit(int n, t4i t, int x, int y){
  auto [l, r, L, R] = t;

  return {
    GetLeftLimit(1, n, x, y, l),
    GetRightLimit(1, n, x, y, r),
    GetLeftLimit(n + 1, 2 * n, x, y, L),
    GetRightLimit(n + 1, 2 * n, x, y, R)
  };
}

ll Calculate(int n){
  if(a.empty()){
    return 0ll;
  }

  t4i t;
  for(int m = a.size(), i = 0; i < m; ++i){
    t = {INT_MAX, INT_MIN, INT_MAX, INT_MIN};
    for(int j = i, k = 1; k <= m; j = (j + 1) % m, ++k){
      t = Update(n, t, a[j]);
      t4i p = GetLimit(n, t, a[(j + 1) % m], a[(i + m - 1) % m]);
      if(k != 1){
        Insert(n, k, t, p);
      }
    }
  }

  ll ans = 0;
  for(auto [key, value]: M){
    ll ansx = 1ll * value.second * (value.first / 2);
    ans += ansx;
    auto [l, r, L, R] = key;
  }

  a.clear(), M.clear();
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x <= 2 * n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    DFS(i);
    ans += Calculate(n);
  }

  printf("%lld\n", ans);
  return 0;
}