#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 41

char s[N][N];
int d[N][N];
vector<pii> moves {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
deque<pii> Q;

void CheckAndPush(int x, int y, int val, bool push_front){
  if(d[x][y] <= val){
    return;
  }
  
  d[x][y] = val;
  if(push_front){
    Q.push_front({x, y});
  }
  else{
    Q.push_back({x, y});
  }
}

int main(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      d[x][y] = k;
    }
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == '@'){
        CheckAndPush(x, y, 0, true);
      }
    }
  }

  while(!Q.empty()){
    int x, y;
    tie(x, y) = Q.front();
    Q.pop_front();

    int val = d[x][y];

    for(pii move: moves){
      int nx = x + move.first, ny = y + move.second;
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '#'){
        continue;
      }

      if(s[nx][ny] == 's'){
        CheckAndPush(nx, ny, 1 + val, false);
      }
      else{
        CheckAndPush(nx, ny, val, true);
      }
    }
  }

  bool ans = false;
  for(int x = 0; x < n && !ans; ++x){
    for(int y = 0; y < m && !ans; ++y){
      ans = s[x][y] == 'x' && 2 * d[x][y] <= k;
    }
  }

  printf("%s\n", ans ? "SUCCESS" : "IMPOSSIBLE");

  return 0;
}