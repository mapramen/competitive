#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<pii>> adj(N);
int color[N];
bool visited[N];

bool DFS(int i, int ci){
  if(visited[i]){
    return color[i] == ci;
  }

  visited[i] = true;
  color[i] = ci;

  bool ans = true;
  for(auto [j, w]: adj[i]){
    ans = ans && DFS(j, 1 ^ ci);
  }

  return ans;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int w, i, j;
    scanf("%d%d%d", &w, &i, &j);
    adj[i].push_back({j, w - 1});
    adj[j].push_back({i, w - 1});
  }

  for(int i = 1; i <= n; ++i){
    if(!DFS(i, color[i])){
      printf("NO\n");
      return 0;
    }
  }

  bool sandwichedColor = false;
  for(int i = 1; i <= n; ++i){
    bool attract = false, repel = false;
    for(auto [j, w]: adj[i]){
      attract = attract || w == 1;
      repel = repel || w == 0;
    }
    
    if(attract && repel){
      sandwichedColor = color[i];
      break;
    }
  }

  vector<pair<char,int>> ans;
  for(int i = 1, mc = 0, lc = -n, rc = n; i <= n; ++i){
    if(color[i] == sandwichedColor){
      ans.push_back({'L', ++mc});
      continue;
    }

    bool attract = false, repel = false;
    for(auto [j, w]: adj[i]){
      attract = attract || w == 1;
      repel = repel || w == 0;
    }

    if(attract && repel){
      printf("NO\n");
      return 0;
    }

    int x = attract ? --lc : ++rc;
    ans.push_back({'R', x});
  }

  printf("YES\n");
  for(auto [c, x]: ans){
    printf("%c %d\n", c, x);
  }

  return 0;
}