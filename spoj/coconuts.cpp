#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

struct Edge{
  int from, to, index;
  ll cap, flow;
  Edge(int from, int to, ll cap, ll flow, int index) : from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel{
  int N;
  vector<vector<Edge>> G;
  vector<ll> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2 * N) {}

  void AddEdge(int from, int to, ll cap){
    G[from].push_back(Edge(from, to, cap, 0ll, G[to].size()));
    if(from == to){
      G[from].back().index++;
    }
    // for undirected
    G[to].push_back(Edge(to, from, cap, 0ll, G[from].size() - 1));

    // for directed
    // G[to].push_back(Edge(to, from, 0ll, 0ll, G[from].size() - 1));
  }

  void Enqueue(int v){
    if(!active[v] && excess[v] > 0){
      active[v] = true;
      Q.push(v);
    }
  }

  void Push(Edge &e){
    ll amt = min(excess[e.from], e.cap - e.flow);
    if(dist[e.from] <= dist[e.to] || amt == 0){
      return;
    }
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
    Enqueue(e.to);
  }

  void Gap(int k){
    for(int v = 0; v < N; ++v){
      if(dist[v] < k){
        continue;
      }
      count[dist[v]]--;
      dist[v] = max(dist[v], N + 1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v){
    count[dist[v]]--;
    dist[v] = 2 * N;
    for(int i = 0; i < G[v].size(); ++i){
      if(G[v][i].cap - G[v][i].flow > 0){
        dist[v] = min(dist[v], dist[G[v][i].to] + 1);
      }
    }
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v){
    for(int i = 0; excess[v] > 0 && i < G[v].size(); ++i){
      Push(G[v][i]);
    }
    if(excess[v] > 0){
      if(count[dist[v]] == 1){
        Gap(dist[v]);
      }
      else{
        Relabel(v);
      }
    }
  }

  ll GetMaxFlow(int s, int t){
    count[0] = N - 1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for(int i = 0; i < G[s].size(); ++i){
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }

    while(!Q.empty()){
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }

    ll totflow = 0;
    for(int i = 0; i < G[s].size(); ++i){
      totflow += G[s][i].flow;
    }
    return totflow;
  }
};

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  if(n == 0){
    exit(0);
  }

  int s = 0, t = n + 1;
  PushRelabel push_relabel = PushRelabel(1 + n + 1);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    if(x == 0){
      push_relabel.AddEdge(s, i, 1);
    }
    else{
      push_relabel.AddEdge(i, t, 1);
    }
  }


  for(int e = 1; e <= m; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    push_relabel.AddEdge(i, j, 1);
  }

  return push_relabel.GetMaxFlow(s, t);
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}