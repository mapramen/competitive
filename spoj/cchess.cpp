#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 8
#define INF 100000

int d[N][N];
vector<pii> moves {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
priority_queue<tiii,vector<tiii>,greater<tiii>> Q;

void CheckAndPush(int x, int y, int val){
  if(x < 0 || x >= N || y < 0 || y >= N || d[x][y] <= val){
    return;
  }

  d[x][y] = val;
  Q.push({val, x, y});
}

int Solve(){
  int sx, sy, tx, ty;
  
  if(scanf("%d%d%d%d", &sx, &sy, &tx, &ty) == EOF){
    exit(0);
  }

  for(int x = 0; x < N; ++x){
    for(int y = 0; y < N; ++y){
      d[x][y] = INF;
    }
  }

  CheckAndPush(sx, sy, 0);

  while(!Q.empty()){
    int val, x, y;
    tie(val, x, y) = Q.top();
    Q.pop();

    if(d[x][y] != val){
      continue;
    }

    for(pii move: moves){
      int nx = x + move.first, ny = y + move.second;
      CheckAndPush(nx, ny, val + x * nx + y * ny);
    }
  }

  return d[tx][ty] == INF ? -1 : d[tx][ty];
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}