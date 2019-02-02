#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 51

int a[5][N], dx[5][N], dy[5][N], turns;
vector< tiii > ans;
queue< pii > Q;

void Initialise(int n){
  vector< pii > v;

  for(int x = 2, y = 1; y <= n; ++y){
    v.PB(MP(x, y));
    if(a[x][y]){
      Q.push(MP(x, y));
    }
  }

  for(int x = 3, y = n; y > 0; --y){
    v.PB(MP(x, y));
    if(a[x][y]){
      Q.push(MP(x, y));
    }
  }

  for(int i = 0; i < v.size(); ++i){
    int j = (i + 1) % v.size();
    int sx, sy, tx, ty;

    tie(sx, sy) = v[i];
    tie(tx, ty) = v[j];

    dx[sx][sy] = tx - sx;
    dy[sx][sy] = ty - sy;
  }
}

void AddMove(int sx, int sy, int tx, int ty){
  ++turns;

  if(a[tx][ty] != 0 && a[tx][ty] != a[sx][sy]){
    Q.push(MP(sx, sy));
    return ;
  }

  ans.PB(MT(a[sx][sy], tx, ty));

  if(a[tx][ty] == a[sx][sy]){
    a[sx][sy] = 0;
  }
  else{
    swap(a[sx][sy], a[tx][ty]);
    Q.push(MP(tx, ty));
  }

  turns = 0;
}

int main(){
  int n, k;

  scanf("%d%d", &n, &k);

  for(int x = 1; x <= 4; ++x){
    for(int y = 1; y <= n; ++y){
      scanf("%d", &a[x][y]);
    }
  }

  Initialise(n);

  while(!Q.empty() && turns <= Q.size()){
    int x, y;
    tie(x, y) = Q.front();
    Q.pop();

    int tx = (x == 2) ? 1 : 4, ty = y;

    if(a[tx][ty] == a[x][y]){
      AddMove(x, y, tx, ty);
      continue;
    }

    tx = x + dx[x][y], ty = y + dy[x][y];
    AddMove(x, y, tx, ty);
  }

  if(Q.empty()){
    printf("%lu\n", ans.size());
    for(auto t : ans){
      int i, r, c;
      tie(i, r, c) = t;
      printf("%d %d %d\n", i, r, c);
    }
  }
  else{
    printf("-1\n");
  }

  return 0;
}
