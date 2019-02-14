#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define PB push_back
#define MP make_pair
#define N 100001
#define LOGN 17
#define M 22

vector< vector<int> > edgeNos(N);
vector<int> v;
int edgeXOR[N], w[N];
ll d[M][N], inf = 1E18;
bool visited[N], edgeVisited[N];

//------------------------------------- LCA -------------------------------------//
int timeIn[N], timeOut[N], timeV[N], indx[N], ind = 1, timer = 1, lcaTable[1 + LOGN][2 * N], lg[2 * N];

void BuildLCASparseTable(int n){
	n = 2 * n - 1;

	for(int i = 2; i <= n; i++)
		lg[i] = 1 + lg[i / 2];

	for(int k = 1; (1 << k) <= n; k++)
		for(int i = 1, j = 1 + (1 << (k - 1)), nk = n - (1 << k) + 1; i <= nk; i++, j++)
			lcaTable[k][i] = min(lcaTable[k - 1][i], lcaTable[k - 1][j]);
}

int LCA(int x, int y){
	x = indx[x], y = indx[y];
	if(x > y) swap(x, y);
	int k = lg[y - x + 1];
	k = min(lcaTable[k][x], lcaTable[k][y - (1 << k) + 1]);
	return timeV[k];
}
//----------------------------------- LCA Ends -----------------------------------//

void DFS(int i, int p = 0){
  visited[i] = 1;
  timeIn[i] = timer++;
  timeV[timeIn[i]] = i;
	indx[i] = ind;
	lcaTable[0][ind++] = timeIn[i];

  for(auto e : edgeNos[i]){
    if(edgeVisited[e]){
      continue;
    }

    int k = (edgeXOR[e] ^ i);
    edgeVisited[e] = 1;

    if(k == p){
      continue;
    }

    if(visited[k]){
      v.PB(i);
      continue;
    }

    d[0][k] = d[0][i] + w[e];
    DFS(k, i);
    lcaTable[0][ind++] = timeIn[i];
  }

  timeOut[i] = timer;
}

void Dijkstra(int n, int s, ll d[]){
  priority_queue< pli > Q;

  for(int i = 1; i <= n; ++i){
    d[i] = inf;
  }

  d[s] = 0;
  Q.push(MP(-d[s], s));

  while(!Q.empty()){
    int i;
    ll di;
    tie(di, i) = Q.top();
    Q.pop();

    di = -di;
    if(di != d[i]){
      continue;
    }

    for(auto e : edgeNos[i]){
      int k = (edgeXOR[e] ^ i);
      ll dk = di + w[e];
      if(dk < d[k]){
        d[k] = dk;
        Q.push(MP(-d[k], k));
      }
    }
  }
}

void PreProcess(int n){
  DFS(1);
  BuildLCASparseTable(n);
  int k = 1;
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for(auto s : v){
    Dijkstra(n, s, d[k]);
    ++k;
  }
}

int main(){
  int n, m, q;

  scanf("%d%d", &n, &m);

  for(int x = 1; x <= m; ++x){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    w[x] = k;
    edgeXOR[x] = (i ^ j);
    edgeNos[i].PB(x);
    edgeNos[j].PB(x);
  }

  PreProcess(n);
  m = v.size();

  scanf("%d", &q);
  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    int k = LCA(i, j);
    ll ans = (d[0][i] - d[0][k]) + (d[0][j] - d[0][k]);
    for(int x = 1; x <= m; ++x){
      ans = min(ans, d[x][i] + d[x][j]);
    }
    printf("%lld\n", ans);
  }

  return 0;
}
