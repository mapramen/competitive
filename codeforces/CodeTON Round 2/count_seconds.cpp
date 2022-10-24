#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define MOD 998244353

vector<vector<int>> adj(N);
int a[N], dp[N], c[N][N];
bool visited[N];
vector<int> topological_order;

void Reset(int n){
  for(int i = 0; i <= n; ++i){
    visited[i] = false;
    adj[i].clear();
    for(int j = 0; j <= n; ++j){
      c[i][j] = 0;
    }
    dp[i] = 0;
  }
  topological_order.clear();
}

void VisitDFS(int i){
  if(visited[i]){
    return;
  }
  
  visited[i] = true;
  for(int j: adj[i]){
    VisitDFS(j);
  }

  topological_order.push_back(i);
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  Reset(n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
  }

  for(int i = 1; i <= n; ++i){
    VisitDFS(i);
  }
  reverse(topological_order.begin(), topological_order.end());

  for(int i: topological_order){
    c[i][0] = min(n, c[i][0] + a[i]), dp[i] = (dp[i] + a[i]) % MOD;

    for(int j: adj[i]){
      dp[j] = (dp[j] + dp[i]) % MOD;
      for(int k = 1; k <= n; ++k){
        c[j][k] = min(n, c[i][k - 1] + c[j][k]);
      }
    }
  }

  int root = topological_order.back(), ans = 0, last_day = 0;
  for(int j = 1, x = 0; j <= n; ++j){
    x = min(n, x + c[root][j - 1]);
    if(x > 0){
      ++ans, --x, last_day = j;
    }
  }

  ans = (MOD + dp[root] - ans) % MOD;
  ans = (ans + last_day) % MOD;

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}