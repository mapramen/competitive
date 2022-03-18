#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001
#define inf 1E9

vector<vector<pii>> adj(N);
int d[N], temp[N];
priority_queue<pii,vector<pii>,greater<pii>> Q;

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
    d[i] = inf;
  }
}

void CheckAndPush(int i, int di){
  if(di < d[i]){
    d[i] = di;
    Q.push({di, i});
  }
}

void RelaxVertex(int i){
  for(pii& p: adj[i]){
    CheckAndPush(p.first, d[i] + p.second);
  }
}

void Dijkstra(int s){
  RelaxVertex(s);
  while(!Q.empty()){
    int i = Q.top().second, di = Q.top().first;
    Q.pop();

    if(di != d[i]){
      continue;
    }
    
    RelaxVertex(i);
  }
}

int Solve(){
  int n, m, k, s, t;
  scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);

  Reset(n);

  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
  }

  d[s] = 0;
  Dijkstra(s);

  for(int i = 1; i <= n; ++i){
    temp[i] = d[i];
  }

  while(k--){
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    temp[u] = min(temp[u], d[v] + w);
    temp[v] = min(temp[v], d[u] + w);
  }

  for(int i = 1; i <= n; ++i){
    if(temp[i] >= d[i]){
      continue;
    }
    d[i] = temp[i];
    Dijkstra(i);
  }

  return d[t] == inf ? -1 : d[t];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}