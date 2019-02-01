#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define M 31

typedef long long LL;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<LL> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void Enqueue(int v) {
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); }
  }

  void Push(Edge &e) {
    int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
    Enqueue(e.to);
  }

  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++)
      if (G[v][i].cap - G[v][i].flow > 0)
	dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1)
	Gap(dist[v]);
      else
	Relabel(v);
    }
  }

  LL GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }

    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }

    LL totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};

int GetAns(int n, int m){
  if(n > m){
    swap(n, m);
  }

  if(n == 1){
    return 6 * (m / 6) + 2 * max(0, m % 6 - 3);
  }

  if(n == 2){
    if(m < 3){
      return 0;
    }
    if(m == 3 || m == 7){
      return 2 * m - 2;
    }
    else{
      return 2 * m;
    }
  }

  return n * m - (n * m) % 2;
}

int main(){
  for(int n = 1; n < M; ++n){
    for(int m = 1; m < M; ++m){
      int t = n * m;

      PushRelabel pr(1 + 2 * t + 1);

      for(int i = 1; i <= t; ++i){
        pr.AddEdge(0, 2 * i - 1, 1);
        pr.AddEdge(2 * i, 2 * t + 1, 1);
      }

      for(int x = 1; x <= n; ++x){
        for(int y = 1; y <= m; ++y){
          for(int dx = -3; dx <= 3; ++dx){
            for(int dy = -3; dy <= 3; ++dy){
              int nx = x + dx, ny = y + dy;
              if(nx <= 0 || nx > n || ny <= 0 || ny > m || abs(dx) + abs(dy) != 3){
                continue;
              }
              // printf("Adding Edge %d %d %d %d\n", x, y, nx, ny);
              int i = (x - 1) * m + y, j = (nx - 1) * m + ny;
              pr.AddEdge(2 * i - 1, 2 * j, 1);
            }
          }
        }
      }

      int ans1 = pr.GetMaxFlow(0, 2 * t + 1), ans2 = GetAns(n, m);

      if(ans1 != ans2){
        printf("%d %d %d %d\n", n, m, ans1, ans2);
      }
    }
  }

  return 0;
}
