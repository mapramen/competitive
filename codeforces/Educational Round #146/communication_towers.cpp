#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define trollback tuple<int,int,int,int>
#define N 200001
#define M (1 << 19)

int l[N], r[N];
pii edges[M], children_components[(1 << 23)];
int parent[N], sz[N], component_number[N], total_components = 0;
bool visited[(1 << 23)];

vector<int> T[M];

void Update(int k, int l, int r, int ql, int qr, int e){
  if(qr < l || r < ql){
    return;
  }

  if(ql <= l && r <= qr){
    T[k].push_back(e);
    return;
  }

  int mid = (l + r) / 2;
  Update(2 * k + 1, l, mid, ql, qr, e);
  Update(2 * k + 2, mid + 1, r, ql, qr, e);
}

int GetNewComponentNumber(int i, int j){
  children_components[++total_components] = {i, j};
  return total_components;
}

int Find(int i){
  return i == parent[i] ? i : Find(parent[i]);
}

int GetComponentNumber(int i){
  return component_number[Find(i)];
}

void AddRollback(vector<trollback>& rollbacks, int i){
  rollbacks.push_back({i, parent[i], sz[i], GetComponentNumber(i)});
}

void Union(vector<trollback>& rollbacks, int i, int j){
  i = Find(i), j = Find(j);

  if(i == j){
    return;
  }

  AddRollback(rollbacks, i);
  AddRollback(rollbacks, j);
  
  if(sz[i] < sz[j]){
    swap(i, j);
  }

  component_number[i] = GetNewComponentNumber(GetComponentNumber(i), GetComponentNumber(j));
  parent[j] = i;
  sz[i] += sz[j];
}

void DivideAndConquer(int k, int l, int r){
  vector<trollback> rollbacks;

  for(int e: T[k]){
    Union(rollbacks, edges[e].first, edges[e].second);
  }

  if(l == r){
    visited[GetComponentNumber(1)] = true;
  }
  else{
    int mid = (l + r) / 2;
    DivideAndConquer(2 * k + 1, l, mid);
    DivideAndConquer(2 * k + 2, mid + 1, r);
  }

  reverse(rollbacks.begin(), rollbacks.end());
  for(trollback& rollback: rollbacks){
    auto [i, pi, szi, component_number_i] = rollback;
    parent[i] = pi, sz[i] = szi, component_number[i] = component_number_i;
  }
  rollbacks.clear();
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &l[i], &r[i]);
  }

  for(int e = 1; e <= m; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    edges[e] = {i, j};

    int x = max(l[i], l[j]), y = min(r[i], r[j]);
    if(x <= y){
      Update(0, 1, N, x, y, e);
    }
  }

  for(int i = 1; i <= n; ++i){
    parent[i] = i, sz[i] = 1, component_number[i] = GetNewComponentNumber(i, i);
  }

  DivideAndConquer(0, 1, N);

  for(int k = total_components; k > 0; --k){
    if(visited[k]){
      visited[children_components[k].first] = true;
      visited[children_components[k].second] = true;
    }
  }

  for(int i = 1; i <= n; ++i){
    if(visited[i]){
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}