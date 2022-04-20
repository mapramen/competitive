#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 21
#define B 11
#define M (1 << B)

char s[N][N];
int d[N][N], cost[B][B], dp[M][B], inf = 5000;
queue<pii> Q;

void CheckAndPush(int n, int m, int x, int y, int dxy){
  if(x < 0 || x >= n || y < 0 || y >= m || d[x][y] != inf || s[x][y] == 'x'){
    return;
  }
  d[x][y] = dxy;
  Q.push({x, y});
}

void BFS(int n, int m, int sx, int sy){
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      d[x][y] = inf;
    }
  }

  CheckAndPush(n, m, sx, sy, 0);

  while(!Q.empty()){
    int x, y;
    tie(x, y) = Q.front();
    Q.pop();

    CheckAndPush(n, m, x - 1, y, d[x][y] + 1);
    CheckAndPush(n, m, x, y - 1, d[x][y] + 1);
    CheckAndPush(n, m, x, y + 1, d[x][y] + 1);
    CheckAndPush(n, m, x + 1, y, d[x][y] + 1);
  }
}

int Solve(){
  int n, m;
  scanf("%d%d", &m, &n);

  if(n == 0){
    exit(0);
  }

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  vector<pii> a;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == '*'){
        a.push_back({x, y});
      }
    }
  }

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      if(s[x][y] == 'o'){
        a.push_back({x, y});
      }
    }
  }

  reverse(a.begin(), a.end());

  int b = a.size();
  for(int i = 0; i < b; ++i){
    BFS(n, m, a[i].first, a[i].second);
    for(int j = 0; j < b; ++j){
      cost[i][j] = d[a[j].first][a[j].second];
    }
  }

  for(int mask = 0; mask < (1 << b); ++mask){
    for(int i = 0; i < b; ++i){
      dp[mask][i] = inf;
    }
  }

  dp[1][0] = 0;
  for(int mask = 1; mask < (1 << b); ++mask){
    for(int i = 0; i < b; ++i){
      if(dp[mask][i] == inf){
        continue;
      }

      for(int j = 0; j < b; ++j){
        int nmask = mask | (1 << j);
        dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + cost[i][j]);
      }
    }
  }

  int ans = *min_element(dp[(1 << b) - 1], dp[(1 << b) - 1] + b);

  return ans == inf ? -1 : ans;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}