#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long LL;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

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

int main(){
  int t;

  cin >> t;

  while(t--){
    int h, v, n;
    cin >> h >> v;
    n = h + v;

    vector< pair< pii, string > > hStrings, vStrings;
    PushRelabel g = PushRelabel(n + 2);

    while(h--){
      int x, y;
      string s;
      cin >> x >> y >> s;
      hStrings.PB(MP(MP(x, y), s));
    }

    while(v--){
      int x, y;
      string s;
      cin >> x >> y >> s;
      vStrings.PB(MP(MP(x, y), s));
    }

    for(int i = 0; i < hStrings.size(); i++){
      for(int j = 0; j < vStrings.size(); j++){
        int x1 = hStrings[i].first.first, y1 = hStrings[i].first.second, l1 = hStrings[i].second.size();
        int x2 = vStrings[j].first.first, y2 = vStrings[j].first.second, l2 = vStrings[j].second.size();

        if((x1 <= x2 && x2 <= x1 + l1 - 1) && (y2 <= y1 && y1 <= y2 + l2 - 1) && (hStrings[i].second[x2 - x1] != vStrings[j].second[y1 - y2]))
          g.AddEdge(i + 1, j + (int)hStrings.size() + 1, 1);
      }
    }

    for(int i = 0; i < hStrings.size(); i++)
      g.AddEdge(0, i + 1, 1);

    for(int j = 0; j < vStrings.size(); j++)
      g.AddEdge(j + (int)hStrings.size() + 1, n + 1, 1);

    cout << n - g.GetMaxFlow(0, n + 1) << '\n';
  }

  return 0;
}
