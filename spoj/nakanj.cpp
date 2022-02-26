#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 8

char s[3];
vector<pii> moves {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
int marker[N][N], d[N][N], timer = 0;
queue<pii> Q;

void CheckAndPush(int x, int y, int dxy){
  if(marker[x][y] != timer){
    marker[x][y] = timer;
    d[x][y] = dxy;
    Q.push({x, y});
  }
}

int Dis(pii s, pii t){
  ++timer;
  
  CheckAndPush(s.first, s.second, 0);

  int tx = t.first, ty = t.second;
  while(marker[tx][ty] != timer){
    int x, y;
    tie(x, y) = Q.front();
    Q.pop();

    for(pii& move: moves){
      int nx = x + move.first, ny = y + move.second;
      if(nx < 0 || nx >= N || ny < 0 || ny >= N){
        continue;
      }

      CheckAndPush(nx, ny, 1 + d[x][y]);
    }
  }

  for( ; !Q.empty(); Q.pop());

  return d[tx][ty];
}

pii ReadCell(){
  scanf("%s", s);
  return {s[0] - 'a', s[1] - '1'};
}

int Solve(){
  return Dis(ReadCell(), ReadCell());
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}