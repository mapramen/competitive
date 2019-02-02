#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

vector< vector<int> > adj(N);
int A[N][N], d1[N], d2[N];

void Dijkstra(int s, int n, int d[]){
  for(int i = 1; i <= n; ++i)
    d[i] = n;

  priority_queue< pii, vector< pii >, greater< pii > > Q;
  d[s] = 0;
  Q.push(MP(d[s], s));

  while(!Q.empty()){
    int i, di;
    tie(di, i) = Q.top();
    Q.pop();

    if(di > d[i])
      continue;

    for(auto k : adj[i]){
      if(d[k] > 1 + d[i]){
        d[k] = 1 + d[i];
        Q.push(MP(d[k], k));
      }
    }
  }
}

void AddEdge(int i, int j){
  adj[i].PB(j);
  adj[j].PB(i);
  A[i][j] = 1;
  A[j][i] = 1;
}

int main(){
  int n, m, s, t;

  scanf("%d%d%d%d", &n, &m, &s, &t);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    AddEdge(i, j);
  }

  Dijkstra(s, n, d1);
  Dijkstra(t, n, d2);

  int ans = 0;
  for(int i = 1; i <= n; ++i)
    for(int j = i + 1; j <= n; ++j)
      ans += (A[i][j] == 0 && d1[i] + 1 + d2[j] >= d1[t] && d1[j] + 1 + d2[i] >= d1[t]);

  printf("%d\n", ans);

  return 0;
}
