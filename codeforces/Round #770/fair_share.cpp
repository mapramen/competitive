#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define edge tuple<int,int,int,int,char>
#define N 300001

vector<vector<edge>> adj(N);
map<int,int> C;
int totalEdges = 0;
bool edgeVisited[N];
string S[N];

int ReadArrayInt(){
  int x;
  scanf("%d", &x);

  auto ct = C.find(x);
  if(ct != C.end()){
    return ct->second;
  }

  int ans = C.size();
  C[x] = ans;
  return ans;
}

void AddEdge(int x, int y, int i, int j){
  adj[x].push_back({totalEdges, y, i, j, 'L'});
  adj[y].push_back({totalEdges, x, i, j, 'R'});
  ++totalEdges;
}

void DFS(int x){
  while(!adj[x].empty()){
    auto [edgeNo, y, i, j, c] = adj[x].back();
    adj[x].pop_back();

    if(edgeVisited[edgeNo]){
      continue;
    }

    edgeVisited[edgeNo] = true;
    S[i][j] = c;
    DFS(y);
  }
}

int main(){
  int m;
  scanf("%d", &m);

  for(int i = 0; i < m; ++i){
    C[-i] = i;
  }

  for(int i = 0; i < m; ++i){
    int n;
    scanf("%d", &n);

    S[i].resize(n);
    for(int j = 0, x = i; j < n; ++j){
      int y = ReadArrayInt();
      AddEdge(x, y, i, j);
    }
  }

  for(int x = C.size() - 1; x != -1; --x){
    if(adj[x].size() % 2 == 1){
      printf("NO\n");
      return 0;
    }
  }

  for(int x = C.size() - 1; x != -1; --x){
    DFS(x);
  }

  printf("YES\n");
  for(int i = 0; i < m; ++i){
    printf("%s\n", S[i].c_str());
  }
 
  return 0;
}