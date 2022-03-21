#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 500

vector<vector<pii>> adj(N), rAdj(N);
int ds[N], dt[N], inf = 1E9;
priority_queue<pii,vector<pii>,greater<pii>> Q;

void Reset(int n){
  for(int i = 0; i < n; ++i){
    adj[i].clear();
    rAdj[i].clear();
  }
}

void CheckAndPush(int d[], int i, int di){
  if(di < d[i]){
    d[i] = di;
    Q.push({di, i});
  }
}

int Dijkstra(vector<vector<pii>>& adj, int d[], int n, int s, int t){
  for(int i = 0; i < n; ++i){
    d[i] = inf;
  }

  CheckAndPush(d, s, 0);
  
  while(!Q.empty()){
    int i, di;
    tie(di, i) = Q.top();
    Q.pop();

    if(di != d[i]){
      continue;
    }

    for(pii p: adj[i]){
      CheckAndPush(d, p.first, di + p.second);
    }
  }

  return d[t] == inf ? -1 : d[t];
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  if(n == 0){
    exit(0);
  }

  int s, t;
  scanf("%d%d", &s, &t);

  Reset(n);

  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    rAdj[j].push_back({i, w});
  }

  int D = Dijkstra(adj, ds, n, s, t);
  if(D == -1){
    return -1;
  }

  Dijkstra(rAdj, dt, n, t, s);

  for(int i = 0; i < n; ++i){
    for(pii& p: adj[i]){
      if(ds[i] + p.second + dt[p.first] == D){
        p.second = inf;
      }
    }
  }

  return Dijkstra(adj, ds, n, s, t);
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}