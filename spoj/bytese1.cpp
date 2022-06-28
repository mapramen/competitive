#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101
#define B 10

vector<vector<pii>> Q(B);
vector<pii> moves {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int a[N][N], d[N][N];

void Reset(int n, int m){
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      d[i][j] = INT_MAX;
    }
  }

  for(int k = 0; k < B; ++k){
    Q[k].clear();
  }
}

void CheckAndPush(int x, int y, int val){
  val += a[x][y];
  if(val < d[x][y]){
    d[x][y] = val;
    Q[val % B].push_back({x, y});
  }
}

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  Reset(n, m);

  CheckAndPush(1, 1, 0);

  for(int k = 0; k < B * (n + m); ++k){
    vector<pii>& v = Q[k % B];
    for(int z = 0; z < v.size(); ++z){
      int x, y;
      tie(x, y) = v[z];
      for(pii& move: moves){
        int nx = x + move.first, ny = y + move.second;
        if(nx <= 0 || nx > n || ny <= 0 || ny > m){
          continue;
        }
        CheckAndPush(nx, ny, d[x][y]);
      }
    }
  }

  int sx, sy, T;
  scanf("%d%d%d", &sx, &sy, &T);

  int ans = T - d[sx][sy];

  if(ans < 0){
    printf("NO\n");
  }
  else{
    printf("YES\n%d\n", ans);
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