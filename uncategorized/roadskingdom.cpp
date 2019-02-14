#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200010

vector< vector< pii > > adj(N);
int parent[N], parentEdgeWeight[N], c1, c2;
vector<int> cycle;
ll h[N], d[N], A[N], B[N], C[N], prefixDiam[N], suffixDiam[N], prefixFar[N], suffixFar[N];

bool visited[N];

void CycleDFS(int i){
  visited[i] = 1;
  for(auto p : adj[i]){
    if(c1)
      break;
    int k, w;
    tie(k, w) = p;
    if(k == parent[i])
      continue;
    parent[k] = i;
    parentEdgeWeight[k] = w;
    if(visited[k])
      c1 = k, c2 = i;
    else
      CycleDFS(k);
  }
}

void GetCycle(int i){
  if(i != c1)
    GetCycle(parent[i]);
  cycle.PB(i);
}

void DFS(int i){
  visited[i] = 1;
  ll ans = 0;
  for(auto p : adj[i]){
    int k, w;
    tie(k, w) = p;
    if(visited[k])
      continue;
    DFS(k);
    d[i] = max(d[i], d[k]);
    d[i] = max(d[i], h[i] + w + h[k]);
    h[i] = max(h[i], w + h[k]);
  }
}

int main(){
  int n;
  ll ans = LLONG_MAX;

  scanf("%d", &n);

  for(int x = 1; x <= n; x++){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].PB(MP(j, w));
    adj[j].PB(MP(i, w));
  }

  CycleDFS(1);

  for(int i = 1; i <= n; i++)
    visited[i] = 0;

  GetCycle(c2);

  for(auto i : cycle)
    visited[i] = 1;

  int m = cycle.size();

  for(int i = 1; i <= m; i++){
    int k = cycle[i - 1];
    DFS(k);
    A[i] = h[k];
    B[i] = d[k];
    C[i] = parentEdgeWeight[k];
  }

  for(ll i = 1, x = 0, y = 0; i <= m; i++){
    prefixDiam[i] = max(prefixDiam[i - 1], max(B[i], x + A[i]));
    prefixFar[i] = max(prefixFar[i - 1], y + A[i]);
    x = max(x, A[i]) + C[i + 1];
    y += C[i + 1];
  }

  for(int i = 0; i <= m; i++)
    C[i] = C[i + 1];
  swap(C[0], C[m]);

  for(ll i = m, x = 0, y = 0; i > 0; i--){
    y += C[i];
    suffixDiam[i] = max(suffixDiam[i + 1], max(B[i], x + A[i]));
    suffixFar[i] = max(suffixFar[i + 1], y + A[i]);
    x = max(x, A[i]) + C[i - 1];
  }

  ans = prefixDiam[m];

  for(int i = 1; i < m; i++){
    ll ansx = max(max(prefixDiam[i], suffixDiam[i + 1]), prefixFar[i] + suffixFar[i + 1]);
    ans = min(ans, ansx);
  }

  printf("%lld\n", ans);

  return 0;
}
