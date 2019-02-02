#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);
vector<int> d(N), parent(N), cycleIndex(N), group, groupSize;
vector< pii > cycles;
map< pii, int > edges;
set<int> ans;

void DFS(int i, int p = -1){
  parent[i] = p;
  d[i] = 1 + d[max(0, p)];

  for(auto k : adj[i]){
    if(k == p){
      continue;
    }
    if(parent[k] == 0){
      DFS(k, i);
    }
    else if(d[k] < d[i]){
      cycles.PB(MP(i, k));
    }
  }
}

int Find(int i){
  return group[i] == i ? i : group[i] = Find(group[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i > j)
    swap(i, j);
  if(i == j){
    return ;
  }
  group[j] = i;
}

void AddEdgeToAns(int i, int j){
  if(i > j)
    swap(i, j);
  ans.insert(edges[MP(i, j)]);
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int x = 1; x <= m; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
    if(i > j)
      swap(i, j);
    edges[MP(i, j)] = x;
  }

  for(int i = 1; i <= n; ++i){
    if(parent[i]){
      continue;
    }
    DFS(i);
  }

  vector<int> p(parent.begin(), parent.end());
  group.resize(cycles.size());
  groupSize.resize(cycles.size());

  fill(cycleIndex.begin(), cycleIndex.end(), -1);

  for(int i = 0; i < cycles.size(); ++i){
    int u, v;
    vector<int> path;

    tie(v, u) = cycles[i];
    group[i] = i;
    for( ; d[v] > d[u]; v = parent[v]){
      path.PB(v);
      if(cycleIndex[v] != -1){
        Union(i, cycleIndex[v]);
      }
      else
        cycleIndex[v] = i;
    }

    for(auto x : path)
      parent[x] = u;
  }

  for(auto x : group)
    ++groupSize[Find(x)];

  parent = p;

  for(int i = 0; i < cycles.size(); ++i){
    if(groupSize[i] != 1){
      continue;
    }

    int u, v;
    tie(v, u) = cycles[i];
    for(AddEdgeToAns(u, v); d[v] > d[u]; v = parent[v]){
      AddEdgeToAns(v, parent[v]);
    }
  }

  printf("%lu\n", ans.size());
  for(auto x : ans)
    cout << x << ' ';
  cout << '\n';

  return 0;
}
