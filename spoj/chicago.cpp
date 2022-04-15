#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pid pair<double,int>
#define N 101

vector<vector<pii>> adj(N);
double d[N];
priority_queue<pair<double,int>> Q;

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }
}

void CheckAndPush(int i, double di){
  if(di > d[i]){
    d[i] = di;
    Q.push({di, i});
  }
}

double Dijkstra(int n){
  for(int i = 1; i <= n; ++i){
    d[i] = 0;
  }

  CheckAndPush(1, 100);

  while(!Q.empty()){
    int i = Q.top().second;
    double di = Q.top().first;
    Q.pop();

    if(di != d[i]){
      continue;
    }

    for(pii& edge: adj[i]){
      int j = edge.first, p = edge.second;
      CheckAndPush(j, di * p / 100);
    }
  }

  return d[n];
}

double Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  Reset(n);

  int m;
  scanf("%d", &m);

  while(m--){
    int i, j, p;
    scanf("%d%d%d", &i, &j, &p);
    adj[i].push_back({j, p});
    adj[j].push_back({i, p});
  }

  return Dijkstra(n);
}

int main(){
  while(true){
    printf("%.6lf percent\n", Solve());
  }
  return 0;
}