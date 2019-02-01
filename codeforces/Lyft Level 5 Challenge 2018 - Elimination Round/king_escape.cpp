#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

int n, ax, ay, bx, by, cx, cy;
bool visited[N][N];

bool DFS(int x, int y){
  int dx = abs(x - ax), dy = abs(y - ay);

  if(x <= 0 || x > n || y <= 0 || y > n || visited[x][y] == 1 || dx == 0 || dy == 0 || dx == dy){
    return 0;
  }

  if(x == cx && y == cy){
    return 1;
  }

  visited[x][y] = 1;

  for(int nx = x - 1; nx <= x + 1; ++nx){
    for(int ny = y - 1; ny <= y + 1; ++ny){
      if(nx == x && ny == y){
        continue;
      }
      if(DFS(nx, ny)){
        return 1;
      }
    }
  }

  return 0;
}

int main(){
  cin >> n >> ax >> ay >> bx >> by >> cx >> cy;

  cout << (DFS(bx, by) ? "YES" : "NO") << '\n';

  return 0;
}
