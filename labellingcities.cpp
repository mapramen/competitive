#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

vector< vector<int> > adj(N);
vector< set<int> > bAdj(N);
int blockNo[N], blockLabel[N];

int PreProcess(int n){
  vector< vector<int> > v;
  for(int i = 1; i <= n; i++){
    adj[i].PB(i);
    sort(adj[i].begin(), adj[i].end());
    v.PB(adj[i]);
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for(int i = 1; i <= n; i++)
    blockNo[i] = lower_bound(v.begin(), v.end(), adj[i]) - v.begin() + 1;

  for(int i = 1; i <= n; i++){
    int x = blockNo[i];
    for(auto k : adj[i]){
      int y = blockNo[k];
      if(y != x){
        bAdj[x].insert(y);
        bAdj[y].insert(x);
      }
    }
  }

  return (int)v.size();
}

void DFS(int i, int p){
  for(auto k : bAdj[i]){
    if(k == p)
      continue;
    blockLabel[k] = blockLabel[i] + 1;
    DFS(k, i);
  }
}

int main(){
  int n, m, root = 0;
  bool valid = 1;

  scanf("%d%d", &n, &m);
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  m = PreProcess(n);

  for(int i = 1; i <= m && valid == 1; i++){
    valid = (bAdj[i].size() <= 2);
    if(bAdj[i].size() <= 1)
      root = i;
  }

  if(valid == 0 || root == 0)
    printf("NO\n");
  else{
    blockLabel[root] = 1;
    DFS(root, 0);

    printf("YES\n");
    for(int i = 1; i <= n; i++)
      printf("%d ", blockLabel[blockNo[i]]);
    printf("\n");
  }

  return 0;
}
