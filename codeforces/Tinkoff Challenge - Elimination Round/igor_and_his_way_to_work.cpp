#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

int n, m;
char s[N][N];
bool visited[N][N][4][3], ans = 0;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void DFS(int i, int j, int dir, int turns){
  if(turns > 2 || i < 0 || j < 0 || i >= n || j >= m || visited[i][j][dir][turns] == 1 || s[i][j] == '*')
    return ;

  visited[i][j][dir][turns] = 1;
  if(s[i][j] == 'T')
    ans = 1;

  for(int new_dir = 0; new_dir < 4; new_dir++){
    if(new_dir == dir)
      DFS(i + dx[new_dir], j + dy[new_dir], new_dir, turns);
    else
      DFS(i + dx[new_dir], j + dy[new_dir], new_dir, turns + 1);
  }
}

int main(){
  int hx, hy;
  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; i++)
    scanf("%s", s[i]);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(s[i][j] == 'S')
        hx = i, hy = j;

  for(int dir = 0; dir < 4 && ans == 0; dir++)
    DFS(hx, hy, dir, 0);

  if(ans)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
