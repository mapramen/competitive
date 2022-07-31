#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tq tuple<int,int,int,int,int>
#define N 200001
#define LOGN 17

vector<vector<int>> adj(N);
int d[N], parent[N], eulerTour[2 * N], startTime[N], finishTime[N], startTimeVertex[2 * N], T[1 + LOGN][N], qAns[N], BLOCK_SIZE, timer, ans;
bool visited[N + 1];
vector<tq> queries;

void DFS(int i, int p){
  d[i] = 1 + d[p];
  parent[i] = p;
  eulerTour[++timer] = i;
  startTime[i] = timer;
  startTimeVertex[startTime[i]] = i;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
  }

  eulerTour[++timer] = i;
  finishTime[i] = timer;
}

void PreProcess(int n, int m){
  DFS(1, 0);
  BLOCK_SIZE = max(1, (int)(2 * n / sqrt(m)));

  for(int i = 1; i <= timer; ++i){
    int v = eulerTour[i];
    if(i != startTime[v] && i != finishTime[v]){
      eulerTour[i] = 0;
    }
  }

  for(int i = 1; i <= n; ++i){
    T[0][i] = parent[i];
  }

  for(int k = 1; k <= LOGN; ++k){
    for(int i = 1; i <= n; ++i){
      T[k][i] = T[k - 1][T[k - 1][i]];
    }
  }

  ans = 0;
}

int KthAncestor(int k, int i){
  for(int x = LOGN; x > -1; --x){
    if((k & (1 << x))){
      i = T[x][i];
      k ^= (1 << x);
    }
  }
  return i;
}

int LCA(int i, int j){
  if(d[i] > d[j]){
    swap(i, j);
  }

  j = KthAncestor(d[j] - d[i], j);

  if(i == j){
    return i;
  }

  for(int k = LOGN; k > -1; --k){
    if(T[k][i] != T[k][j]){
      i = T[k][i], j = T[k][j];
    }
  }

  return parent[i];
}

tq GetMOQuery(int k, int u, int v){
  int w = LCA(u, v);

  if(w == v){
    swap(u, v);
  }

  if(w == u){
    return {finishTime[v] / BLOCK_SIZE, finishTime[u], finishTime[v], 0, k};
  }

  if(finishTime[v] < startTime[u]){
    swap(u, v);
  }

  return {finishTime[u] / BLOCK_SIZE, startTime[v], finishTime[u], w, k};
}

void Update(int x){
  if(x == 0){
    return;
  }

  visited[x] = !visited[x];

  if(visited[x]){
    ++ans;
    ans -= (visited[x - 1]);
    ans -= (visited[x + 1]);
  }
  else{
    --ans;
    ans += (visited[x - 1]);
    ans += (visited[x + 1]);
  }
}

void Toggle(int i){
  Update(eulerTour[i]);
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  PreProcess(n, m);

  for(int k = 1; k <= m; ++k){
    int u, v;
    scanf("%d%d", &u, &v);
    queries.push_back(GetMOQuery(k, u, v));
  }
  sort(queries.begin(), queries.end());

  int L = 1, R = 0;
  for(tq& q: queries){
    int r = get<1>(q), l = get<2>(q), i = get<3>(q), k = get<4>(q);

    for(++R; R <= r; ++R){
      Toggle(R);
    }
    --R;

    for( ; r < R; --R){
      Toggle(R);
    }

    for(--L; l <= L; --L){
      Toggle(L);
    }
    ++L;

    for( ; L < l; ++L){
      Toggle(L);
    }

    Update(i);
    qAns[k] = ans;
    Update(i);
  }

  for(int k = 1; k <= m; ++k){
    printf("%d\n", qAns[k]);
  }

  return 0;
}