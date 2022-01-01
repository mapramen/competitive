#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define N 200001

vector<vector<int>> adj(N);
int d[N], parent[N];
bool marked[N];

void DFS(int i, int p){
  parent[i] = p;
  d[i] = 1 + d[p];

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
  }
}

int main(){
  int n, k;
  scanf("%d%d", &n, &k);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);

  vector<pii> v;
  for(int i = 1; i <= n; ++i){
    v.push_back({d[i], i});
  }
  sort(v.begin(), v.end(), greater<pii>());

  for(auto& q: v){
    auto [_, i] = q;

    int c = 0;
    while(i != 0 && !marked[i]){
      ++c;
      marked[i] = true;
      i = parent[i];
    }

    q.first = c;
  }
  
  sort(v.begin(), v.end(), greater<pii>());

  ll ans = LLONG_MIN;
  for(int r = 1, s = 0; r <= k; ++r){
    s += v[r - 1].first;
    int b = min(n / 2, n - s);

    ll ansx = 1ll * r * (n - r) - 1ll * b * (n - b);
    ans = max(ans, ansx);
  }

  printf("%lld\n", ans);

  return 0;
}