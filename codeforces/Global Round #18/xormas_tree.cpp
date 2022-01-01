#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 200001

vector<vector<pii>> adj(N);
vector<tiii> edges;
int color[N];
bool visited[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    visited[i] = false;
    adj[i].clear();
  }
  edges.clear();
}

bool ColorDFS(int i, int c){
  if(visited[i]){
    return color[i] == c;
  }

  visited[i] = true;
  color[i] = c;

  bool ans = true;
  for(auto [j, w]: adj[i]){
    ans = ans && ColorDFS(j, c ^ w);
  }

  return ans;
}
 
void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  Reset(n);
 
  for(int x = 1; x < n; ++x){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);

    edges.push_back({i, j, w});

    if(w != -1){
      w = __builtin_popcount(w) % 2;
      adj[i].push_back({j, w});
      adj[j].push_back({i, w});
    }
  }

  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  bool ans = true;
  for(int i = 1; i <= n; ++i){
    if(!visited[i]){
      ans = ans && ColorDFS(i, 0);
    }
  }

  if(!ans){
    printf("NO\n");
    return;
  }
 
  printf("YES\n");
  for(auto [i, j, w]: edges){
    if(w == -1){
      w = color[i] ^ color[j];
    }

    printf("%d %d %d\n", i, j, w);
  }
}
 
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}