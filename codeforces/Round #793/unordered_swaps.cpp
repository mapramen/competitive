#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> adj(N), V(N);
int a[N], p[N];
map<pii,int> swap_index;
vector<int> topological_order;
bool visited[N];

void VisitDFS(int i){
  if(visited[i]){
    return;
  }
  
  visited[i] = true;
  for(int j: adj[i]){
    VisitDFS(j);
  }

  topological_order.push_back(i);
}

int GetSwapIndex(int x, int y){
  auto it = swap_index.find({min(x, y), max(x, y)});
  return it == swap_index.end() ? 0 : it->second;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &p[i]);
  }

  for(int k = 1; k <= m; ++k){
    int x, y;
    scanf("%d%d", &x, &y);
    swap_index[{min(x, y), max(x, y)}] = k;
    V[x].push_back(y), V[y].push_back(x);
  }

  for(int i = 1; i <= n; ++i){
    if(p[i] == 0){
      continue;
    }

    vector<int> v;
    for(int j = i; j != 0; ){
      v.push_back(j);
      int k = p[j];
      p[j] = 0;
      j = k;
    }
    v.pop_back();

    for(int k = 0; k < v.size(); ++k){
      a[v[k]] = k;
    }

    for(int j: v){
      sort(V[j].begin(), V[j].end(), [](int x, int y) { return a[x] > a[y]; });
      a[j] += N;
    }
  }

  for(int i = 1; i <= n; ++i){
    vector<int>& v = V[i];
    for(int k = 1; k < v.size(); ++k){
      adj[GetSwapIndex(i, v[k - 1])].push_back(GetSwapIndex(i, v[k]));
    }
  }

  for(int i = 1; i <= m; ++i){
    VisitDFS(i);
  }

  for(int k: topological_order){
    printf("%d ", k);
  }
  printf("\n");

  return 0;
}