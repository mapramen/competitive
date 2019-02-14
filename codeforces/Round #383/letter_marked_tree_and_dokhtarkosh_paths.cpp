#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500001
#define B 22

vector< vector<int> > adj(N), w(N), subtree(N);
int d[N], mask[N], subtreeSize[N], heavyChild[N], subtreeNo[N], parent[N], h[(1 << B)], ans[N];
bool visited[N];

void Initialise(int n){
  for(int i = 0; i < (1 << B); i++)
    h[i] = INT_MIN;

  for(int i = 1; i <= n; i++){
    heavyChild[i] = i;
    subtreeNo[i] = i;
  }
}

void HeavyLightDFS(int i){
  visited[i] = 1;

  for(int j = 0; j < adj[i].size(); j++){
    int k = adj[i][j];

    if(visited[k] == 0){
      parent[k] = i;
      d[k] = d[i] + 1;
      mask[k] = (mask[i] ^ (1 << w[i][j]));
      HeavyLightDFS(k);
      heavyChild[i] = (subtreeSize[k] > subtreeSize[heavyChild[i]]) ? k : heavyChild[i];
      subtreeSize[i] += subtreeSize[k];
    }
  }

  subtreeNo[i] = subtreeNo[heavyChild[i]];
  subtreeSize[i]++;
}

void ResetBag(int i){
  for(auto x : subtree[i])
    h[mask[x]] = INT_MIN;
}

void Update(int i){
  h[mask[i]] = max(h[mask[i]], d[i]);
}

int Query(int root, int x){
  int ans = max(-(d[x] - 2 * d[root]), h[mask[x]]);
  for(int i = 0; i < B; i++)
    ans = max(ans, h[(mask[x] ^ (1 << i))]);
  ans += d[x] - 2 * d[root];
  return ans;
}

int QueryLightChild(int root, int child){
  int ans = 0;
  for(auto k : subtree[child])
    ans = max(ans, Query(root, k));
  return ans;
}

void CopyLightChild(int root, int child){
  for(auto k : subtree[child]){
    subtree[root].PB(k);
    Update(k);
  }
}

void DFS(int i){
  for(auto k : adj[i]){
    if(k != parent[i] && k != heavyChild[i]){
      DFS(k);
      ResetBag(subtreeNo[k]);
    }
  }

  if(heavyChild[i] != i)
    DFS(heavyChild[i]);

  for(auto k : adj[i]){
    if(k == parent[i])
      continue;

    if(k != heavyChild[i]){
      ans[i] = max(ans[i], QueryLightChild(i, subtreeNo[k]));
      CopyLightChild(subtreeNo[i], subtreeNo[k]);
    }

    ans[i] = max(ans[i], ans[k]);
  }

  Update(i);
  ans[i] = max(ans[i], Query(i, i));
  subtree[subtreeNo[i]].PB(i);
}

void AddEdge(int i, int j, int k){
  adj[i].PB(j);
  w[i].PB(k);
}

int main(){
  int n, i, j, k;
  char s[2];

  scanf("%d", &n);

  for(i = 2; i <= n; i++){
    scanf("%d", &j);
    scanf("%s", s);
    k = s[0] - 'a';
    AddEdge(i, j, k);
    AddEdge(j, i, k);
  }

  Initialise(n);
  HeavyLightDFS(1);
  DFS(1);

  for(i = 1; i <= n; i++)
    printf("%d ", ans[i]);
  printf("\n");

  return 0;
}
