#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 26

char s[N][N];
int n, m, a[N][N], d[N][N], inf = 10000;
priority_queue<tiii,vector<tiii>,greater<tiii>> Q;

void CheckAndPush(int x, int y, int dxy){
  if(x < 0 || x >= n || y < 0 || y >= m){
    return;
  }

  dxy += a[x][y];

  if(dxy < d[x][y]){
    d[x][y] = dxy;
    Q.push({dxy, x, y});
  }
}

int Dijkstra(int sx, int sy, int tx, int ty){
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      d[x][y] = inf;
    }
  }

  CheckAndPush(sx, sy, 0);

  while(!Q.empty()){
    tiii t = Q.top();
    Q.pop();

    int x = get<1>(t), y = get<2>(t), dxy = get<0>(t);
    if(d[x][y] != dxy){
      continue;
    }

    CheckAndPush(x - 1, y, dxy);
    CheckAndPush(x, y - 1, dxy);
    CheckAndPush(x, y + 1, dxy);
    CheckAndPush(x + 1, y, dxy);
  }

  return d[tx][ty];
}

int Solve(){
  scanf("%d%d", &m, &n);

  if(n == 0){
    exit(0);
  }

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  int sx, sy, tx, ty;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == 'S'){
        sx = x, sy = y, a[x][y] = 0;
      }
      else if(s[x][y] == 'D'){
        tx = x, ty = y, a[x][y] = 0;
      }
      else if(s[x][y] == 'X'){
        a[x][y] = inf;
      }
      else{
        a[x][y] = s[x][y] - '0';
      }
    }
  }

  return Dijkstra(sx, sy, tx, ty);
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}