#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<pii> moves {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<string> s(n);
  for(string& sx: s){
    cin >> sx;
  }

  queue<pii> Q;
  vector<vector<int>> d(n, vector<int>(m, n + m));

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == '1'){
        d[x][y] = 0, Q.push({x, y});
      }
    }
  }

  while(!Q.empty()){
    int x, y;
    tie(x, y) = Q.front();
    Q.pop();

    for(pii& move: moves){
      int nx = x + move.first, ny = y + move.second;
      if(nx < 0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] == '1'){
        continue;
      }
      s[nx][ny] = '1';
      d[nx][ny] = 1 + d[x][y];
      Q.push({nx, ny});
    }
  }

  for(vector<int>& dx: d){
    for(int& dxy: dx){
      printf("%d ", dxy);
    }
    printf("\n");
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