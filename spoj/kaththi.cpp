#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

char s[N][N];
int dp[N][N];
deque<pii> Q;
vector<pii> moves = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void Reset(int n, int m){
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      dp[x][y] = INT_MAX;
    }
  }
  Q.clear();
}

void CheckAndPush(int x, int y, int dpxy, bool front){
  if(dpxy >= dp[x][y]){
    return;
  }

  dp[x][y] = dpxy;

  if(front){
    Q.push_front({x, y});
  }
  else{
    Q.push_back({x, y});
  }
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  Reset(n, m);

  CheckAndPush(0, 0, 0, true);

  while(!Q.empty() && (Q.front().first != n - 1 || Q.front().second != m - 1)){
    int x, y;
    tie(x, y) = Q.front();
    Q.pop_front();

    for(pii& move: moves){
      int nx = x + move.first, ny = y + move.second;
      if(nx < 0 || nx >= n || ny < 0 || ny >= m){
        continue;
      }
      CheckAndPush(nx, ny, dp[x][y] + (s[nx][ny] != s[x][y]), s[nx][ny] == s[x][y]);
    }
  }

  return dp[n - 1][m - 1];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}