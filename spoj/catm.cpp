#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

bool visited[N][N];

void Reset(int n, int m){
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= m; ++j){
      visited[i][j] = false;
    }
  }
}

int Dis(pii a, pii b){
  return abs(a.first - b.first) + abs(a.second - b.second);
}

bool DFS(int n, int m, pii mouse, pii cat1, pii cat2, int x, int y){
  if(x <= 0 || x > n || y <= 0 || y > m){
    return true;
  }

  if(visited[x][y]){
    return false;
  }

  visited[x][y] = true;
  
  pii cell = {x, y};
  if(min(Dis(cat1, cell), Dis(cat2, cell)) <= Dis(mouse, cell)){
    return false;
  }

  return DFS(n, m, mouse, cat1, cat2, x - 1, y)
      || DFS(n, m, mouse, cat1, cat2, x, y - 1)
      || DFS(n, m, mouse, cat1, cat2, x, y + 1)
      || DFS(n, m, mouse, cat1, cat2, x - 1, y);
}

int main(){
  int n, m, q;
  scanf("%d%d", &n, &m);

  scanf("%d", &q);

  while(q--){
    Reset(n, m);
    
    int x, y, x1, y1, x2, y2;
    scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);

    printf("%s\n", DFS(n, m, {x, y}, {x1, y1}, {x2, y2}, x, y) ? "YES" : "NO");
  }
  
  return 0;
}