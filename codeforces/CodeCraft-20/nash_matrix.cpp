#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 1001

const int dx[] = {0, -1, 0, 0, 1};
const int dy[] = {0, 0, -1, 1, 0};

pii a[N][N], b[N][N];
int n, d[N][N];
bool visited[N][N];
char s[N], moves[] = {'X', 'U', 'L', 'R', 'D'};

void DFS(int x, int y){
  if(a[x][y].first == -1 || visited[x][y] == true){
    return;
  }

  visited[x][y] = true;
  
  for(int k = 1; k <= 4; ++k){
    int nx = x + dx[k], ny = y + dy[k];

    if(nx <= 0 || nx > n || ny <= 0 || ny > n || a[nx][ny] != a[x][y] || visited[nx][ny] == true){
      continue;
    }

    d[nx][ny] = 5 - k;
    DFS(nx, ny);
  }
}

bool DFSCycle(int x, int y, int px, int py){
  if(a[x][y].first != -1){
    return false;
  }

  if(visited[x][y] == true){
    return true;
  }

  visited[x][y] = true;

  for(int k = 1; k <= 4; ++k){
    int nx = x + dx[k], ny = y + dy[k];

    if(nx <= 0 || nx > n || ny <= 0 || ny > n || a[nx][ny] != a[x][y]){
      continue;
    }

    d[x][y] = k;
    
    if(DFSCycle(nx, ny, x, y) == true){
      return true;
    }
  }

  return false;
}

void CheckDFS(int x, int y){
  visited[x][y] = true;
  
  for(int k = 1; k <= 4; ++k){
    int nx = x + dx[k], ny = y + dy[k];

    if(nx <= 0 || nx > n || ny <= 0 || ny > n || visited[nx][ny] == true || nx + dx[d[nx][ny]] != x || ny + dy[d[nx][ny]] != y){
      continue;
    }

    b[nx][ny] = b[x][y];
    CheckDFS(nx, ny);
  }
}

bool Check(){
  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= n; ++y){
      visited[x][y] = false;
      b[x][y] = make_pair(-1, -1);
    }
  }

  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= n; ++y){
      if(d[x][y] != 0 || visited[x][y] == true){
        continue;
      }
      
      b[x][y] = make_pair(x, y);
      CheckDFS(x, y);
    }
  }

  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= n; ++y){
      if(a[x][y] != b[x][y]){
        return false;
      }
    }
  }

  return true;
}

void Print(){
  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= n; ++y){
      s[y - 1] = moves[d[x][y]];
    }
    s[n] = '\0';
    printf("%s\n", s);
  }
}

int main(){
  scanf("%d", &n);

  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= n; ++y){
      int i, j;
      scanf("%d%d", &i, &j);
      a[x][y] = make_pair(i, j);
    }
  }

  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= n; ++y){
      if(a[x][y] == make_pair(x, y)){
        DFS(x, y);
      }
      
      if(a[x][y] == make_pair(-1, -1)){
        DFSCycle(x, y, 0, 0);
      }
    }
  }

  if(Check() == false){
    printf("INVALID\n");
  }
  else{
    printf("VALID\n");
    Print();
  }

  return 0;
}