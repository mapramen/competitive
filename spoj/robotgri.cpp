#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

char s[N][N];
int dp[N], MOD = (1ll << 31) - 1;
bool visited[N][N];
queue<pii> Q;

void CheckAndPush(int n, int x, int y){
  if(x < 0 || x >= n || y < 0 || y >= n || s[x][y] == '#' || visited[x][y]){
    return;
  }
  visited[x][y] = true;
  Q.push({x, y});
}

bool BFS(int n, vector<pii> moves){
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < n; ++y){
      visited[x][y] = false;
    }
  }

  CheckAndPush(n, 0, 0);

  while(!Q.empty()){
    int x, y;
    tie(x, y) = Q.front();
    Q.pop();

    for(pii& move: moves){
      CheckAndPush(n, x + move.first, y + move.second);
    }
  }

  return visited[n - 1][n - 1];
}

int main(){
  int n;
  scanf("%d", &n);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  if(!BFS(n, {{-1, 0}, {0, -1}, {0, 1}, {1, 0}})){
    printf("INCONCEIVABLE\n");
    return 0;
  }

  if(!BFS(n, {{0, 1}, {1, 0}})){
    printf("THE GAME IS A LIE\n");
    return 0;
  }

  for(int y = 0; y <= n; ++y){
    dp[y] = 0;
  }

  dp[1] = 1;
  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= n; ++y){
      dp[y] = s[x - 1][y - 1] == '#' ? 0 : (0ll + dp[y - 1] + dp[y]) % MOD;
    }
  }

  printf("%d\n", dp[n]);

  return 0;
}