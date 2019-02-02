#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 10001
#define M 102

vector< vector<int> > adj(N);
int dp[N][M][2], inf = 1E9, p, m, op1 = -1, op2 = 1;
char s[N];

void Initialise(){
  for(int i = 1; i < N; ++i)
    for(int j = 0; j < M; ++j)
      dp[i][j][0] = -inf, dp[i][j][1] = inf;
}

void PreProcess(){
  int n = 1;
  stack<int> S;
  S.push(n);

  for(int i = 0; s[i] != '\0'; ++i){
    char c = s[i];
    if(c == '('){
      ++n;
      adj[S.top()].PB(n);
      S.push(n);
    }
    else if(c == ')'){
      S.pop();
    }
    else if(c != '?'){
      adj[S.top()].PB(++n);
      dp[n][0][0] = dp[n][0][1] = c - '0';
    }
  }
}

void DFS(int i){
  for(auto k : adj[i])
    DFS(k);

  if(adj[i].size() == 0)
    return ;

  if(adj[i].size() == 1){
    int k = adj[i][0];
    for(int j = 0; j <= m; ++j)
      dp[i][j][0] = dp[k][j][0], dp[i][j][1] = dp[k][j][1];
    return ;
  }

  int k1 = adj[i][0], k2 = adj[i][1];
  for(int x = 0; x <= m; ++x){
    for(int y = 0, z = x; y <= m - x; ++y, ++z){
      for(int a = 0; a < 2; ++a){
        for(int b = 0; b < 2; ++b){
          if(abs(dp[k1][x][a]) == inf || abs(dp[k2][y][b]) == inf)
            continue;
          int val = dp[k1][x][a] + op1 * dp[k2][y][b];
          dp[i][z + 1][0] = max(dp[i][z + 1][0], val);
          dp[i][z + 1][1] = min(dp[i][z + 1][1], val);

          val += 2 * op2 * dp[k2][y][b];
          dp[i][z][0] = max(dp[i][z][0], val);
          dp[i][z][1] = min(dp[i][z][1], val);
        }
      }
    }
  }
}

int main(){
  scanf("%s%d%d", s, &p, &m);

  if(m > p){
    swap(p, m);
    swap(op1, op2);
  }

  Initialise();
  PreProcess();

  DFS(1);

  printf("%d\n", dp[1][m][0]);

  return 0;
}
