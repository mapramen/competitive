#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define K 8
#define N 1001

vector<pii> moves{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
char s[N][N];
int d[N][N];
int visited[N][N];
queue<pii> Q;

void CheckAndPush(int x, int y, int val){
  if(d[x][y] != INT_MAX){
    return;
  }
  d[x][y] = val;
  Q.push({x, y});
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  int sx, sy, tx, ty;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == 'S'){
        sx = x, sy = y;
      }

      if(s[x][y] == 'F'){
        tx = x, ty = y;
      }

      d[x][y] = INT_MAX;
      visited[x][y] = 0;
    }
  }

  CheckAndPush(sx, sy, 0);

  while(!Q.empty() && d[tx][ty] == INT_MAX){
    int x, y;
    tie(x, y) = Q.front();
    Q.pop();

    int val = 1 + d[x][y];

    for(int k = 0; k < K; ++k){
      int dx = moves[k].first, dy = moves[k].second, direction_mask = (1 << min(k, (k + (K / 2)) % K));
      for(int nx = x + dx, ny = y + dy; nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] != 'X' && (visited[nx][ny] & direction_mask) == 0; nx += dx, ny += dy){
        visited[nx][ny] |= direction_mask;
        CheckAndPush(nx, ny, val);
      }
    }
  }

  while(!Q.empty()){
    Q.pop();
  }

  return d[tx][ty] == INT_MAX ? -1 : d[tx][ty];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}