#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< int, pii >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 10001

vector< vector<int> > rows(N), columns(N);
set< pii > cells;
vector< map< int , int > > dis(N);
priority_queue< piii, vector< piii >, greater< piii > > Q;

int n, m, inf = INT_MAX;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void CheckAndInsert(int i, int j, int d){
  if(i <= 0 || i > n || j <= 0 || j > m)
    return ;

  pii p = MP(i, j);
  if(d < dis[i][j]){
    Q.push(MP(d, p));
    dis[i][j] = d;
  }
}

void AddRow(int i, int d, bool f){
  if(i <= 0 || i > n)
    return ;

  if(f == 1){
    for(auto j : rows[i])
      CheckAndInsert(i, j, d);
  }
  else if(i == n)
    CheckAndInsert(n, m, d);
}

void AddColumn(int j, int d, int f){
  if(j <= 0 || j > m)
    return ;

  if(f == 1){
    for(auto i : columns[j])
      CheckAndInsert(i, j, d);
  }
  else if(j == m)
    CheckAndInsert(n, m, d);
}

int main(){
  int k, ans = -1;

  scanf("%d%d%d", &n, &m, &k);

  while(k--){
    int i, j;
    scanf("%d%d", &i, &j);
    rows[i].PB(j);
    columns[j].PB(i);
    cells.insert(MP(i, j));
    dis[i][j] = inf;
  }

  dis[n][m] = inf;

  CheckAndInsert(1, 1, 0);

  while(!Q.empty()){
    int x, y, d;
    tie(x, y) = Q.top().second;
    d = Q.top().first;
    Q.pop();

    if(dis[x][y] != d)
      continue;

    if(x == n && y == m){
      ans = d;
      break;
    }

    for(int k = 0; k < 4; k++){
      int nx = x + dx[k], ny = y + dy[k];
      if(cells.find(MP(nx, ny)) != cells.end()){
        CheckAndInsert(x + dx[k], y + dy[k], d);
      }
    }

    AddRow(x, d + 1, 1);
    AddRow(x, d + 1, 0);
    AddColumn(y, d + 1, 1);
    AddColumn(y, d + 1, 0);

    AddRow(x + 1, d + 1, 0);
    AddRow(x - 1, d + 1, 0);
    AddColumn(y + 1, d + 1, 0);
    AddColumn(y - 1, d + 1, 0);

    AddRow(x + 1, d + 1, 1);
    AddRow(x - 1, d + 1, 1);
    AddColumn(y + 1, d + 1, 1);
    AddColumn(y - 1, d + 1, 1);

    AddRow(x + 2, d + 1, 1);
    AddRow(x - 2, d + 1, 1);
    AddColumn(y + 2, d + 1, 1);
    AddColumn(y - 2, d + 1, 1);
  }

  printf("%d\n", ans);

  return 0;
}
