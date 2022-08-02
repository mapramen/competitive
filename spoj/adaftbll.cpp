#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tq tuple<int,int,int,int>
#define tqc tuple<int,int,int>
#define N 100001
#define LOGN 16

vector<vector<int>> adj(N);
int a[N], d[N], parent[N], eulerTour[2 * N], startTime[N], finishTime[N], T[1 + LOGN][N], c[N], BLOCK_SIZE, timer;
ll qAns[N], ans;
bool visited[N];
vector<tq> queries;

void DFS(int i, int p){
  d[i] = 1 + d[p];
  parent[i] = p;
  eulerTour[++timer] = i;
  startTime[i] = timer;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
  }

  eulerTour[++timer] = i;
  finishTime[i] = timer;
}

void SetBlockSize(int n){
  BLOCK_SIZE = max(1, (int)cbrt(1.0 * n * n * (1 + (1.0 * n / N))));
}

void PreProcess(int n, int m){
  SetBlockSize(2 * n);
  DFS(1, 0);

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
    return {2, finishTime[v], finishTime[u], 0};
  }

  if(finishTime[v] < startTime[u]){
    swap(u, v);
  }

  return {2, finishTime[u], startTime[v], w};
}

tqc GetMOQueryCompare(int k){
  return {get<1>(queries[k]) / BLOCK_SIZE, get<2>(queries[k]) / BLOCK_SIZE, k};
}

void Add(int i){
  if(i == 0){
    return;
  }

  int k = a[i];
  ans += c[k];
  ++c[k];
}

void Remove(int i){
  if(i == 0){
    return;
  }

  int k = a[i];
  --c[k];
  ans -= c[k];
}

void Toggle(int i){
  i = eulerTour[i];
  visited[i] = !visited[i];
  
  if(visited[i]){
    Add(i);
  }
  else{
    Remove(i);
  }
}

void ApplyOperation(int k){
  if(get<0>(queries[k]) == 2){
    return;
  }

  int i = get<1>(queries[k]), val = get<2>(queries[k]);

  queries[k] = {1, i, a[i], 0};

  if(visited[i]){
    Remove(i);
    a[i] = val;
    Add(i);
  }
  else{
    a[i] = val;
  }
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    ++i, ++j;
    
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  PreProcess(n, q);

  vector<int> query_indexes;
  for(int k = 0; k < q; ++k){
    int t, i, j;
    scanf("%d%d%d", &t, &i, &j);
    if(t == 1){
      queries.push_back({1, i + 1, j, 0});
    }
    else{
      queries.push_back(GetMOQuery(k, i + 1, j + 1));
      query_indexes.push_back(k);
    }
  }

  sort(query_indexes.begin(), query_indexes.end(), [](int i, int j) { return GetMOQueryCompare(i) < GetMOQueryCompare(j); });

  int L = 1, R = 0, K = 0;
  for(int k: query_indexes){
    tq q = queries[k];
    int l = get<1>(q), r = get<2>(q), i = get<3>(q);

    for( ; K <= k; ++K){
      ApplyOperation(K);
    }
    --K;

    for( ; k < K; --K){
      ApplyOperation(K);
    }

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

    Add(i);
    qAns[k] = ans;
    Remove(i);
  }

  for(int k = 0; k < q; ++k){
    if(get<0>(queries[k]) == 1){
      continue;
    }
    printf("%lld\n", qAns[k]);
  }

  return 0;
}