#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

queue<pair<int,int>> Q;
vector<pii> directions {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<string> s(n);
  for(int i = 0; i < n; ++i){
    cin >> s[i];
  }

  int sx = -1, sy = -1;
  for(int x = 0; x < n && sx == -1; ++x){
    for(int y = 0; y < m && sx == -1; ++y){
      if(s[x][y] == 'L'){
        sx = x, sy = y;
      }
    }
  }

  Q.push({sx, sy});

  while(!Q.empty()){
    auto [x, y] = Q.front();
    Q.pop();

    int labDirectionMoveCount = 0, freeMoveCount = 0;
    for(auto [dx, dy]: directions){
      int nx = x + dx, ny = y + dy;
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '#'){
        continue;
      }
      labDirectionMoveCount += (s[nx][ny] == 'L' || s[nx][ny] == '+');
      freeMoveCount += (s[nx][ny] == '.');
    }

    if(s[x][y] == '.' && labDirectionMoveCount > 0 && freeMoveCount < 2){
      s[x][y] = '+';
    }

    if(s[x][y] != 'L' && s[x][y] != '+'){
      continue;
    }

    for(auto [dx, dy]: directions){
      int nx = x + dx, ny = y + dy;
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] != '.'){
        continue;
      }
      Q.push({nx, ny});
    }
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == '!'){
        s[x][y] = '.';
      }
    }
  }

  for(int x = 0; x < n; ++x){
    cout << s[x] << '\n';
  }
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    Solve();
  }

  return 0;
}