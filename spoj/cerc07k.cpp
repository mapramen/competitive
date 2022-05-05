#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 101
#define B 4
#define M (1 << B)

char s[N][N];
int n, m, dp[N][N][M];
queue<tiii> Q;

int GetMask(char c){
  if(c == 'b'){
    return 1;
  }

  if(c == 'g'){
    return 2;
  }

  if(c == 'r'){
    return 4;
  }

  if(c == 'y'){
    return 8;
  }

  return 0;
}

bool IsCellBlocked(char c, int mask){
  if(c == '*' || c == '.' || c == 'X' || ('a' <= c && c <= 'z')){
    return false;
  }

  return (mask & GetMask(tolower(c))) == 0;
}

void CheckAndPush(int x, int y, int mask, int val){
  if(x < 0 || x >= n || y < 0 || y >= m || IsCellBlocked(s[x][y], mask)){
    return;
  }
  
  mask |= GetMask(s[x][y]);

  if(dp[x][y][mask] == INT_MAX){
    dp[x][y][mask] = val;
    Q.push({x, y, mask});
  }
}

int Solve(){
  scanf("%d%d", &n, &m);
  
  if(n == 0){
    exit(0);
  }

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  int sx = -1, sy = -1;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      for(int mask = 0; mask < M; ++mask){
        dp[x][y][mask] = INT_MAX;
      }
      if(s[x][y] == '*'){
        sx = x, sy = y;
      }
    }
  }

  while(!Q.empty()){
    Q.pop();
  }

  CheckAndPush(sx, sy, 0, 0);
  while(!Q.empty()){
    tiii t = Q.front();
    Q.pop();

    int x = get<0>(t), y = get<1>(t), mask = get<2>(t);
    int val = dp[x][y][mask];

    if(s[x][y] == 'X'){
      return val;
    }

    CheckAndPush(x - 1, y, mask, val + 1);
    CheckAndPush(x, y - 1, mask, val + 1);
    CheckAndPush(x, y + 1, mask, val + 1);
    CheckAndPush(x + 1, y, mask, val + 1);
  }

  return -1;
}

int main(){
  while(true){
    int ans = Solve();
    if(ans == -1){
      printf("The poor student is trapped!\n");
    }
    else{
      printf("Escape possible in %d steps.\n", ans);
    }
  }
  return 0;
}