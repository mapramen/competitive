#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101
#define MOD 998244353 

vector<vector<int>> adj(N);
pii a[N];
int d[N][N], dp[2][N];
bool edge[N][N], visited[N];

void ResetVisited(int n){
  for(int i = 1; i <= n; ++i){
    visited[i] = false;
  }
}

void DFS(vector<int>& v, int i){
  if(visited[i]){
    return;
  }

  visited[i] = true;
  v.push_back(i);

  for(int j: adj[i]){
    DFS(v, j);
  }
}

void ResetDP(int n, int dp[]){
  for(int x = 0; x <= n; ++x){
    dp[x] = 0;
  }
}

void UpdateDP(int n, int src[], int des[], int c){
  for(int x = c; x <= n; ++x){
    des[x] = (des[x] + src[x - c]) % MOD;
  }
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i].first, &a[i].second);
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      d[i][j] = abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
    }
  }

  for(int i = 1; i <= n; ++i){
    int min_dis = INT_MAX;
    for(int j = 1; j <= n; ++j){
      if(j != i && d[i][j] < min_dis){
        min_dis = d[i][j];
      }
    }

    for(int j = 1; j <= n; ++j){
      if(d[i][j] != min_dis){
        continue;
      }
      edge[i][j] = true;
      adj[i].push_back(j);
    }

    edge[i][i] = true;
  }

  vector<vector<int>> V;
  for(int i = 1; i <= n; ++i){
    ResetVisited(n);
    vector<int> v;
    DFS(v, i);

    bool valid = true;
    for(int x: v){
      for(int y: v){
        valid = valid && edge[x][y];
      }
    }

    if(!valid){
      v.clear();
      v = {i};
    }

    sort(v.begin(), v.end());
    V.push_back(v);
  }
  sort(V.begin(), V.end());
  V.erase(unique(V.begin(), V.end()), V.end());

  int cur = 0;
  dp[cur][0] = 1;
  for(vector<int>& v: V){
    int nxt = 1 ^ cur;
    ResetDP(n, dp[nxt]);

    UpdateDP(n, dp[cur], dp[nxt], 1);
    if(v.size() != 1){
      UpdateDP(n, dp[cur], dp[nxt], v.size());
    }

    swap(cur, nxt);
  }

  int ans = 0;
  for(int i = 1, mul = 1; i <= n; ++i){
    mul = (1ll * mul * (n - i + 1)) % MOD;
    ans = (ans + 1ll * mul * dp[cur][i]) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}