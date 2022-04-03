#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define MOD 1000000007

vector<vector<int>> adj(N);
int d[N], dp[2][N];
bool visited[2][N];
queue<int> Q;

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
    d[i] = n;
    visited[0][i] = false, visited[1][i] = false;
  }
}

void CheckAndPush(int i, int di){
  if(di < d[i]){
    d[i] = di;
    Q.push(i);
  }
}

void BFS(int s){
  CheckAndPush(s, 0);

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    for(int j: adj[i]){
      CheckAndPush(j, 1 + d[i]);
    }
  }
}

int DFS(int i, int di){
  if(di - d[i] > 1){
    return 0;
  }

  int x = di - d[i];
  if(visited[x][i]){
    return dp[x][i];
  }

  int ans = 0;
  for(int j: adj[i]){
    ans = (ans + DFS(j, di + 1)) % MOD;
  }

  visited[x][i] = true;
  dp[x][i] = ans;
  return ans;
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  int s, t;
  scanf("%d%d", &s, &t);

  Reset(n);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  BFS(s);

  visited[0][t] = true, visited[1][t] = true;
  dp[0][t] = 1, dp[1][t] = 1;

  return DFS(s, 0);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}