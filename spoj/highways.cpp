#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<pii>> adj(N);
int d[N], inf = 1E9;
priority_queue<pii,vector<pii>,greater<pii>> Q;

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }
}

void CheckAndPush(int i, int di){
  if(di < d[i]){
    d[i] = di;
    Q.push({di, i});
  }
}

int Dijkstra(int n, int s, int t){
  for(int i = 1; i <= n; ++i){
    d[i] = inf;
  }

  CheckAndPush(s, 0);
  
  while(!Q.empty()){
    int i, di;
    tie(di, i) = Q.top();
    Q.pop();

    if(di != d[i]){
      continue;
    }

    for(pii p: adj[i]){
      CheckAndPush(p.first, di + p.second);
    }
  }

  return d[t] == inf ? -1 : d[t];
}

string Solve(){
  int n, m, s, t;
  scanf("%d%d%d%d", &n, &m, &s, &t);

  Reset(n);

  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  int D = Dijkstra(n, s, t);
  return D == -1 ? "NONE" : to_string(D);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}