#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2001

char s[N][N];
int d[N][N], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main(){
  int n, m, p, q, r, c;

  scanf("%d%d%d%d%d%d", &n, &m, &r, &c, &p, &q);

  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  --r, --c;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      d[i][j] = INT_MAX;
    }
  }

  deque< pii > Q;
  Q.push_back(MP(r, c));
  d[r][c] = 0;

  while(!Q.empty()){
    int x, y;
    tie(x, y) = Q.front();
    Q.pop_front();

    for(int k = 0; k < 4; ++k){
      int nx = x + dx[k], ny = y + dy[k], nd = d[x][y] + (ny < y);
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] != '.' || d[nx][ny] <= nd){
        continue;
      }
      d[nx][ny] = nd;
      if(ny < y){
        Q.push_back(MP(nx, ny));
      }
      else{
        Q.push_front(MP(nx, ny));
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      int L = d[i][j], R = L + (j - c);
      ans += (L >= 0 && L <= p && R >= 0 && R <= q);
    }
  }

  printf("%d\n", ans);

  return 0;
}
