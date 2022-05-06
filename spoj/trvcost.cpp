#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 501
#define inf 1E9

vector<vector<pii>> adj(N);
int d[N];
priority_queue<pii,vector<pii>,greater<pii>> Q;

void Reset(){
  for(int i = 0; i < N; ++i){
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

int main(){
  int m;
  scanf("%d", &m);

  Reset();

  for(int e = 1; e <= m; ++e){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  int s;
  scanf("%d", &s);

  d[s] = 0;
  Dijkstra(s);

  int q;
  scanf("%d", &q);

  while(q--){
    int t;
    scanf("%d", &t);

    int ans = d[t];
    if(ans == inf){
      printf("NO PATH\n");
    }
    else{
      printf("%d\n", ans);
    }
  }

  return 0;
}