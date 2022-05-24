#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 10
#define N 50

int a[N][N], d[B];
bool visited[N][N];

void Reset(int n){
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < n; ++y){
      visited[x][y] = false;
    }
  }
}

bool DFS(int n, int mask, int sx, int sy, int tx, int ty){
  if(sx < 0 || sx >= n || sy < 0 || sy >= n || visited[sx][sy] || (mask & (1 << a[sx][sy])) == 0){
    return false;
  }

  visited[sx][sy] = true;
  if(sx == tx && sy == ty){
    return true;
  }

  return  DFS(n, mask, sx - 1, sy, tx, ty)
      ||  DFS(n, mask, sx, sy - 1, tx, ty)
      ||  DFS(n, mask, sx, sy + 1, tx, ty)
      ||  DFS(n, mask, sx + 1, sy, tx, ty);
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < n; ++y){
      scanf("%d", &a[x][y]);
    }
  }

  int sx, sy, tx, ty;
  scanf("%d%d%d%d", &sx, &sy, &tx, &ty);

  int ans = B;
  for(int mask = 0; mask < (1 << B); ++mask){
    Reset(n);
    if(DFS(n, mask, sx, sy, tx, ty)){
      ans = min(ans, (int)__builtin_popcount(mask));
    }
  }
  
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}