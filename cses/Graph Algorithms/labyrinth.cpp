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

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

pii parent[N][N];
char s[N][N], parentMove[N][N];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dMove[] = {'D', 'R', 'U', 'L'};

int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
  }

  int sx = -1, sy = -1, tx = -1, ty = -1;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == 'A'){
        sx = x, sy = y;
      }

      if(s[x][y] == 'B'){
        tx = x, ty = y;
      }
    }
  }


  queue<pii> Q;
  Q.push({sx, sy});
  parentMove[sx][sy] = 'X';

  while(!Q.empty() && parentMove[tx][ty] == 0){
    auto [x, y] = Q.front();
    Q.pop();

    for(int k = 0; k < 4; ++k){
      int nx = x + dx[k], ny = y + dy[k];
      if(nx < 0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] == '#' || parentMove[nx][ny] != 0){
        continue;
      }
      parentMove[nx][ny] = dMove[k];
      parent[nx][ny] = {x, y};
      Q.push({nx, ny});
    }
  }

  if(parentMove[tx][ty] == 0){
    printf("NO\n");
    return 0;
  }

  printf("YES\n");
  
  string ans;
  for(int x = tx, y = ty; x != sx || y != sy; tie(x, y) = parent[x][y]){
    ans.push_back(parentMove[x][y]);
  }
  reverse(ans.begin(), ans.end());

  cout << ans.size() << '\n' << ans << '\n';

  return 0;
}