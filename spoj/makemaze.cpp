#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 21

char s[N][N];

pii GetEntryPoint(int n, int m, int c){
  int sx = n, sy = m;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if((x != 0 && x != n - 1 && y != 0 && y != m - 1) || s[x][y] == '#'){
        continue;
      }
      c -= (s[x][y] == '.');
      sx = x, sy = y;
    }
  }
  return c != 0 ? make_pair(n, m) : make_pair(sx, sy);
}

void DFS(int n, int m, int x, int y){
  if(x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '#'){
    return;
  }

  s[x][y] = '#';
  DFS(n, m, x - 1, y);
  DFS(n, m, x, y - 1);
  DFS(n, m, x, y + 1);
  DFS(n, m, x + 1, y);
}

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  int sx, sy;
  tie(sx, sy) = GetEntryPoint(n, m, 2);
  if(sx == n && sy == m){
    return false;
  }

  DFS(n, m, sx, sy);

  tie(sx, sy) = GetEntryPoint(n, m, 1);
  return sx == n && sy == m;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "valid" : "invalid");
  }
  return 0;
}