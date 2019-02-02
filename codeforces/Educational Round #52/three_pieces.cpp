#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiiii tuple< int, int, int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 11
#define B 3

vector< pii > adj[N * N][B];
pii dp[N * N][N * N][B];
int n, A[N][N];
int bishopDx[] = {1, -1, -1, 1}, bishopDy[] = {1, 1, -1, -1}, rookDx[] = {1, 0, -1, 0}, rookDy[] = {0, 1, 0, -1};
priority_queue< tiiiii, vector< tiiiii >, greater< tiiiii > > Q;

bool CheckBoundary(int x, int y){
  if(x <= 0 || x > n || y <= 0 || y > n){
    return 0;
  }
  else{
    return 1;
  }
}

void AddEdge(int i, int j, int ni, int nj){
  adj[i][j].PB(MP(ni, nj));
}

void AddEdge(int i, int x, int y){
  for(int dx = -2; dx <= 2; ++dx){
    for(int dy = -2; dy <= 2; ++dy){
      int nx = x + dx, ny = y + dy;
      if((abs(dx) + abs(dy)) != 3 || !CheckBoundary(nx, ny)){
        continue;
      }
      AddEdge(i, 0, A[nx][ny], 0);
    }
  }

  for(int k = 0; k < 4; ++k){
    for(int l = 1; l <= n; ++l){
      int nx = x + l * bishopDx[k], ny = y + l * bishopDy[k];
      if(!CheckBoundary(nx, ny)){
        continue;
      }
      AddEdge(i, 1, A[nx][ny], 1);
    }
  }

  for(int k = 0; k < 4; ++k){
    for(int l = 1; l <= n; ++l){
      int nx = x + l * rookDx[k], ny = y + l * rookDy[k];
      if(!CheckBoundary(nx, ny)){
        continue;
      }
      AddEdge(i, 2, A[nx][ny], 2);
    }
  }
}

void Relax(int x, int y, int k, int i, int j){
  pii p = MP(x, y);
  if(p >= dp[k][i][j]){
    return ;
  }
  dp[k][i][j] = p;
  Q.push(MT(x, y, k, i, j));
}

void PreProcess(){
  for(int i = 1; i <= n * n; ++i){
    for(int j = 0; j < B; ++j){
      for(int k = 0; k < B; ++k){
        if(k != j){
          adj[i][j].PB(MP(i, k));
        }
      }
    }
  }

  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= n; ++y){
      AddEdge(A[x][y], x, y);
    }
  }

  for(int k = 1; k <= n * n; ++k){
    for(int i = 1; i <= n * n; ++i){
      for(int j = 0; j < B; ++j){
        dp[k][i][j] = MP(INT_MAX, INT_MAX);
      }
    }
  }

  for(int j = 0; j < B; ++j){
    Relax(0, 0, 1, 1, j);
  }
}

int main(){
  cin >> n;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      cin >> A[i][j];
    }
  }

  PreProcess();

  while(!Q.empty()){
    int x, y, k, i, j;
    tie(x, y, k, i, j) = Q.top();
    Q.pop();

    if(dp[k][i][j] != MP(x, y)){
      continue;
    }

    if(k == n * n){
      cout << x << ' ' << y << '\n';
      return 0;
    }

    for(auto p : adj[i][j]){
      int ni, nj;
      tie(ni, nj) = p;
      Relax(x + 1, y + (j != nj), k + (k + 1 == ni), ni, nj);
    }
  }

  return 0;
}
