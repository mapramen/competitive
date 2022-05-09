#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 252

char s[N][N];

void DFS(int n, int m, int x, int y, int& sheep_count, int& wolf_count){
  if(x < 0 || x > n || y < 0 || y > m || s[x][y] == '#'){
    return ;
  }

  sheep_count += s[x][y] == 'k', wolf_count += s[x][y] == 'v';
  s[x][y] = '#';

  DFS(n, m, x - 1, y, sheep_count, wolf_count);
  DFS(n, m, x, y - 1, sheep_count, wolf_count);
  DFS(n, m, x, y + 1, sheep_count, wolf_count);
  DFS(n, m, x + 1, y, sheep_count, wolf_count);
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 1; x <= n; ++x){
    scanf("%s", s[x] + 1);
  }

  for(int y = 0; y <= m + 1; ++y){
    s[0][y] = '.', s[n + 1][y] = '.';
  }

  for(int x = 0; x <= n + 1; ++x){
    s[x][0] = '.', s[x][m + 1] = '.';
  }

  int ans_sheeps = 0, ans_wolves = 0;
  for(int x = 0; x <= n + 1; ++x){
    for(int y = 0; y <= m + 1; ++y){
      int sheep_count = 0, wolf_count = 0;
      DFS(n + 1, m + 1, x, y, sheep_count, wolf_count);

      if(x == 0 && y == 0){
        ans_sheeps += sheep_count, ans_wolves += wolf_count;
        continue;
      }

      if(sheep_count > wolf_count){
        ans_sheeps += sheep_count;
      }
      else{
        ans_wolves += wolf_count;
      }
    }
  }

  printf("%d %d\n", ans_sheeps, ans_wolves);

  return 0;
}