#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

char s[N][N];
int d[N][N];
queue<pii> Q;

void CheckAndPush(int n, int m, int x, int y, int dxy){
  if(x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '#' || d[x][y] != INT_MAX){
    return;
  }

  d[x][y] = dxy;
  Q.push({x, y});
}

void BFS(int n, int m, int sx, int sy){
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      d[x][y] = INT_MAX;
    }
  }

  CheckAndPush(n, m, sx, sy, 0);

  while(!Q.empty()){
    int x, y;
    tie(x, y) = Q.front();
    Q.pop();

    int dxy = d[x][y];
    CheckAndPush(n, m, x - 1, y, 1 + dxy);
    CheckAndPush(n, m, x, y - 1, 1 + dxy);
    CheckAndPush(n, m, x, y + 1, 1 + dxy);
    CheckAndPush(n, m, x + 1, y, 1 + dxy);
  }
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  int sx = -1, sy = -1;
  for(int x = 0; x < n && sx == -1; ++x){
    for(int y = 0; y < m && sy == -1; ++y){
      if(s[x][y] == 'C'){
        sx = x, sy = y;
      }
    }
  }

  BFS(n, m, sx, sy);

  int ans = 0, max_dist = 0;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == 'S'){
        ans += (60 + 2 * d[x][y]);
        max_dist = max(max_dist, d[x][y]);
      }
    }
  }

  return ans - max_dist;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}