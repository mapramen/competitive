#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101
#define M (N * N)

char s[N];
string S[N][N];
vector<vector<int>> adj(N), V(M);
int pair_index[N][N], parent[M], D[N][N];
bool visited[N];
vector<pii> pairs;
queue<pii> Q;

string ReadString(){
  scanf("%s", s);
  return string(s);
}

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
}

void CheckAndPush(int i, int d){
  if(visited[i]){
    return;
  }

  visited[i] = true;
  Q.push({i, d});
}

bool BFS(int n, int s){
  for(int i = 0; i <= n; ++i){
    visited[i] = false;
  }

  CheckAndPush(s, 0);

  while(!Q.empty()){
    auto [i, d] = Q.front();
    Q.pop();

    D[s][i] = d;
    for(int j: adj[i]){
      CheckAndPush(j, d + 1);
    }
  }

  for(int i = 1; i <= n; ++i){
    if(!visited[i]){
      return false;
    }
  }

  return true;
}

bool IsValid(int n, int m, vector<int>& pair_indexes){
  if(pair_indexes.size() != n - 1){
    return false;
  }

  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }

  for(int k: pair_indexes){
    auto [i, j] = pairs[k];
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    if(!BFS(n, i)){
      return false;
    }
  }

  for(int i = 1; i < n; ++i){
    for(int j = i + 1; j <= n; ++j){
      string& s = S[i][j];
      for(int k = 1; k <= n; ++k){
        if((s[k - 1] == '1') != (D[k][i] == D[k][j])){
          return false;
        }
      }
    }
  }

  printf("YES\n");
  for(int k: pair_indexes){
    auto [i, j] = pairs[k];
    printf("%d %d\n", i, j);
  }

  return true;
}

void Solve(){
  int n;
  scanf("%d", &n);

  pairs.clear();
  for(int i = 1; i <= n; ++i){
    for(int j = i; j <= n; ++j){
      pairs.push_back({i, j});
    }
  }

  int m = pairs.size();
  for(int k = 0; k < m; ++k){
    auto [i, j] = pairs[k];
    pair_index[i][j] = k, pair_index[j][i] = k;
    
    parent[k] = k;
    V[k].clear();
  }

  for(int i = 1; i < n; ++i){
    for(int j = i + 1; j <= n; ++j){
      string& s = S[i][j];
      s = ReadString();
      for(int k = 1; k <= n; ++k){
        if(s[k - 1] == '1'){
          Union(pair_index[i][k], pair_index[j][k]);
        }
      }
    }
  }
  
  for(int k = 0; k < m; ++k){
    V[Find(k)].push_back(k);
  }

  for(int k = 0; k < m; ++k){
    if(IsValid(n, m, V[k])){
      return;
    }
  }

  printf("NO\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}