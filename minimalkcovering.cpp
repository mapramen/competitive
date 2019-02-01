#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define MAXN 4001

struct Edge {
  int from, to, cap, flow, index, edgeNo;
  Edge(int from, int to, int cap, int flow, int index, int edgeNo = 0) :
    from(from), to(to), cap(cap), flow(flow), index(index), edgeNo(edgeNo) {}
};

struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<LL> excess;
  vector<int> dist, count;
  vector<bool> active;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void AddEdge(int from, int to, int cap, int edgeNo = 0) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size(), edgeNo));
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
    excess[s] = 0;
    fill(dist.begin(), dist.end(), 0);
    fill(count.begin(), count.end(), 0);

    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;

    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += (G[s][i].cap - G[s][i].flow);
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

int degree[MAXN], valid[MAXN];

int main(){
  int n1, n2, m;

  scanf("%d%d%d", &n1, &n2, &m);

  PushRelabel pushRelabel(1 + n1 + n2 + 1);
  int s = 0, t = n1 + n2 + 1;

  for(int x = 1; x <= m; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    j += n1;
    pushRelabel.AddEdge(i, j, 1, x);
    ++degree[i];
    ++degree[j];
  }

  int minDegree = m;
  for(int i = 1; i <= n1 + n2; ++i)
    minDegree = min(minDegree, degree[i]);

  for(int i = 1; i <= n1; ++i)
    pushRelabel.AddEdge(s, i, degree[i] - minDegree - 1);

  for(int j = n1 + 1; j <= n1 + n2; ++j)
    pushRelabel.AddEdge(j, t, degree[j] - minDegree - 1);

  vector< vector<int> > ans(minDegree + 1);

  for(int k = minDegree; k > 0; --k){
    for(int i = 0; i < pushRelabel.G[s].size(); ++i)
      ++pushRelabel.G[s][i].cap;

    for(int i = 0; i < pushRelabel.G[t].size(); ++i){
      int j = pushRelabel.G[t][i].to;
      int x = pushRelabel.G[t][i].index;
      ++pushRelabel.G[j][x].cap;
    }

    for(int x = 1; x <= m; ++x)
      valid[x] = 1;

    pushRelabel.GetMaxFlow(s, t);

    for(int i = 1; i <= n1; ++i){
      for(auto edge : pushRelabel.G[i]){
        if(edge.flow == 1 && edge.edgeNo > 0){
          valid[edge.edgeNo] = 0;
        }
      }
    }

    for(int x = 1; x <= m; ++x){
      if(valid[x]){
        ans[k].push_back(x);
      }
    }
  }

  for(auto v : ans){
    printf("%lu ", v.size());
    for(auto x : v){
      printf("%d ", x);
    }
    printf("\n");
  }

  return 0;
}
