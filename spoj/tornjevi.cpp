#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101
#define M (4 * N * N)

char s[N][N];
int horizontal_direction[N][N], vertical_direction[N][N], horizontal_cannonball_vertex[N][N], vertical_cannonball_vertex[N][N];

vector<vector<int>> adj(M), reverse_adj(M);
vector<int> topological_order;
int assigned[M];
bool visited[M];

void Reset(int n){
  for(int i = 0; i < 2 * n; ++i){
    adj[i].clear(), reverse_adj[i].clear();
    assigned[i] = 0, visited[i] = false;
  }
}

int GetLiteralAssignedValue(int x){
  return assigned[x] > assigned[x ^ 1];
}

int Not(int x){
  return x ^ 1;
}

void AddEdge(int x, int y){
  adj[x].push_back(y);
  reverse_adj[y].push_back(x);
}

void AddOr(int x, int y){
  AddEdge(Not(x), y);
  AddEdge(Not(y), x);
}

void AddImplies(int x, int y){
  AddOr(Not(x), y);
}

void AddMust(int x){
  AddOr(x, x);
}

void AddNot(int x){
  AddMust(Not(x));
}

void VisitDFS(int i){
  if(visited[i]){
    return;
  }
  
  visited[i] = true;
  for(int j: adj[i]){
    VisitDFS(j);
  }

  topological_order.push_back(i);
}

void AssignDFS(int i, int x){
  if(assigned[i]){
    return;
  }

  assigned[i] = x;
  for(int j: reverse_adj[i]){
    AssignDFS(j, x);
  }
}

bool Run2Sat(int n){
  n *= 2;
  for(int i = 0; i < n; ++i){
    VisitDFS(i);
  }
  reverse(topological_order.begin(), topological_order.end());

  int m = 0;
  for(int i: topological_order){
    AssignDFS(i, ++m);
    m -= (assigned[i] != m);
  }

  for(int i = 0; i < n; ++i){
    if(assigned[i] == assigned[i ^ 1]){
      return false;
    }
  }

  return true;
}

int GetCellIndex(int n, int m, int x, int y){
  return m * x + y;
}

int GetLeftDirectionVertex(int cell_index){
  return 4 * cell_index;
}

int GetRightDirectionVertex(int cell_index){
  return 4 * cell_index + 1;
}

int GetUpDirectionVertex(int cell_index){
  return 4 * cell_index + 2;
}

int GetDownDirectionVertex(int cell_index){
  return 4 * cell_index + 3;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  Reset(2 * n * m);

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      horizontal_direction[x][y] = -1, vertical_direction[x][y] = -1;
      horizontal_cannonball_vertex[x][y] = -1, vertical_cannonball_vertex[x][y] = -1;
    }
  }

  for(int x = 0; x < n; ++x){
    for(int y1 = 0; y1 < m; ++y1){
      if(s[x][y1] != 'T'){
        continue;
      }

      int y2 = y1 + 1;
      for( ; y2 < m && s[x][y2] != '#' && s[x][y2] != 'T'; ++y2);

      if(y2 < m && s[x][y2] == 'T'){
        horizontal_direction[x][y1] = 0, horizontal_direction[x][y2] = 1;
        AddMust(GetLeftDirectionVertex(GetCellIndex(n, m, x, y1)));
        AddMust(GetRightDirectionVertex(GetCellIndex(n, m, x, y2)));
      }

      y1 = y2;
    }
  }

  for(int y = 0; y < m; ++y){
    for(int x1 = 0; x1 < n; ++x1){
      if(s[x1][y] != 'T'){
        continue;
      }

      int x2 = x1 + 1;
      for( ; x2 < n && s[x2][y] != '#' && s[x2][y] != 'T'; ++x2);

      if(x2 < n && s[x2][y] == 'T'){
        vertical_direction[x1][y] = 0, vertical_direction[x2][y] = 1;
        AddMust(GetUpDirectionVertex(GetCellIndex(n, m, x1, y)));
        AddMust(GetDownDirectionVertex(GetCellIndex(n, m, x2, y)));
      }

      x1 = x2;
    }
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] != 'n'){
        continue;
      }

      for(int cy = y - 1; cy >= 0 && cy < m && s[x][cy] != '#'; --cy){
        if(s[x][cy] == 'T' && horizontal_direction[x][cy] != 0){
          horizontal_cannonball_vertex[x][y] = GetRightDirectionVertex(GetCellIndex(n, m, x, cy));
        }
      }

      for(int cy = y + 1; cy >= 0 && cy < m && s[x][cy] != '#'; ++cy){
        if(s[x][cy] == 'T' && horizontal_direction[x][cy] != 1){
          horizontal_cannonball_vertex[x][y] = GetLeftDirectionVertex(GetCellIndex(n, m, x, cy));
        }
      }

      for(int cx = x - 1; cx >= 0 && cx < n && s[cx][y] != '#'; --cx){
        if(s[cx][y] == 'T' && vertical_direction[cx][y] != 0){
          vertical_cannonball_vertex[x][y] = GetDownDirectionVertex(GetCellIndex(n, m, cx, y));
        }
      }

      for(int cx = x + 1; cx >= 0 && cx < n && s[cx][y] != '#'; ++cx){
        if(s[cx][y] == 'T' && vertical_direction[cx][y] != 1){
          vertical_cannonball_vertex[x][y] = GetUpDirectionVertex(GetCellIndex(n, m, cx, y));
        }
      }
    }
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      vector<int> v;
      if(horizontal_cannonball_vertex[x][y] != -1){
        v.push_back(horizontal_cannonball_vertex[x][y]);
      }

      if(vertical_cannonball_vertex[x][y] != -1){
        v.push_back(vertical_cannonball_vertex[x][y]);
      }

      if(v.empty()){
        continue;
      }

      AddOr(v.front(), v.back());
    }
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] != 'T'){
        continue;
      }

      int cell_index = GetCellIndex(n, m, x, y);
      AddOr(GetLeftDirectionVertex(cell_index), GetRightDirectionVertex(cell_index));
      AddOr(GetUpDirectionVertex(cell_index), GetDownDirectionVertex(cell_index));
    }
  }

  Run2Sat(2 * n * m);

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] != 'T'){
        continue;
      }

      int cell_index = GetCellIndex(n, m, x, y);
      bool direct_right = GetLiteralAssignedValue(GetRightDirectionVertex(cell_index));
      bool direct_down = GetLiteralAssignedValue(GetDownDirectionVertex(cell_index));

      int value = direct_down
                ? direct_right ? 2 : 1
                : direct_right ? 3 : 4;

      s[x][y] = '0' + value;
    }
  }

  for(int x = 0; x < n; ++x){
    printf("%s\n", s[x]);
  }

  return 0;
}