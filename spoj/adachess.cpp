#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 8
#define N (B * B)
#define K 5

vector<vector<int>> adj[K];
int d[K][N][N], inf = 1E9;
queue<int> Q;

int GetCellNumber(int x, int y){
  return B * x + y;
}

void InitializeKingMoves(vector<vector<int>>& adj){
  for(int x = 0; x < B; ++x){
    for(int y = 0; y < B; ++y){
      int i = GetCellNumber(x, y);
      for(int dx = -1; dx < 2; ++dx){
        for(int dy = -1; dy < 2; ++dy){
          int nx = x + dx, ny = y + dy;
          if((nx == x && ny == y) || nx < 0 || nx >= B || ny < 0 || ny >= B){
            continue;
          }
          adj[i].push_back(GetCellNumber(nx, ny));
        }
      }
    }
  }
}

void InitializeKnightMoves(vector<vector<int>>& adj){
  for(int x = 0; x < B; ++x){
    for(int y = 0; y < B; ++y){
      int i = GetCellNumber(x, y);
      for(int dx = -2; dx < 3; ++dx){
        for(int dy = -2; dy < 3; ++dy){
          int nx = x + dx, ny = y + dy;
          if(abs(dx) + abs(dy) != 3 || nx < 0 || nx >= B || ny < 0 || ny >= B){
            continue;
          }
          adj[i].push_back(GetCellNumber(nx, ny));
        }
      }
    }
  }
}

void InitializeTowerMoves(vector<vector<int>>& adj){
  for(int x = 0; x < B; ++x){
    for(int y = 0; y < B; ++y){
      int i = GetCellNumber(x, y);
      
      for(int nx = 0, ny = y; nx < B; ++nx){
        if(nx == x){
          continue;
        }
        adj[i].push_back(GetCellNumber(nx, ny));
      }
      
      for(int ny = 0, nx = x; ny < B; ++ny){
        if(ny == y){
          continue;
        }
        adj[i].push_back(GetCellNumber(nx, ny));
      }
    }
  }
}

void InitializeBishopMoves(vector<vector<int>>& adj){
  for(int x = 0; x < B; ++x){
    for(int y = 0; y < B; ++y){
      int i = GetCellNumber(x, y);
      
      for(int nx = 0; nx < B; ++nx){
        int ny = (nx - x) + y;
        if(nx == x || ny < 0 || ny >= B){
          continue;
        }
        adj[i].push_back(GetCellNumber(nx, ny));
      }
      
      for(int nx = 0; nx < B; ++nx){
        int ny = x + y - nx;
        if(nx == x || ny < 0 || ny >= B){
          continue;
        }
        adj[i].push_back(GetCellNumber(nx, ny));
      }
    }
  }
}

void InitializeQueenMoves(vector<vector<int>>& adj){
  InitializeTowerMoves(adj);
  InitializeBishopMoves(adj);
}

void BFS(vector<vector<int>>& adj, int d[N], int s){
  for(int i = 0; i < N; ++i){
    d[i] = inf;
  }

  d[s] = 0;
  Q.push(s);

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    for(int j: adj[i]){
      if(d[j] == inf){
        d[j] = 1 + d[i];
        Q.push(j);
      }
    }
  }
}

void AllPairShortestPath(vector<vector<int>>& adj, int d[N][N]){
  for(int i = 0; i < N; ++i){
    BFS(adj, d[i], i);
  }
}

void Initialize(){
  for(int k = 0; k < K; ++k){
    adj[k] = vector<vector<int>>(N);
  }

  InitializeKingMoves(adj[0]);
  InitializeKnightMoves(adj[1]);
  InitializeQueenMoves(adj[2]);
  InitializeTowerMoves(adj[3]);
  InitializeBishopMoves(adj[4]);

  for(int k = 0; k < K; ++k){
    AllPairShortestPath(adj[k], d[k]);
  }
}

string Solve(){
  int k1, x1, y1, k2, x2, y2;
  scanf("%d%d%d%d%d%d", &k1, &x1, &y1, &k2, &x2, &y2);

  int a = GetCellNumber(x1, y1), b = GetCellNumber(x2, y2);

  int ans = inf;
  for(int c = 0; c < N; ++c){
    ans = min(ans, d[k1][a][c] + d[k2][b][c]);
  }

  return ans == inf ? "INF" : to_string(ans);
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  
  return 0;
}