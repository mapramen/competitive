#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<pii>> adj(N);
int a[N];
ll dp[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }
}

ll DownDFS(int i, int p){
  ll ans = 0;
  for(pii& edge: adj[i]){
    int j, w;
    tie(j, w) = edge;
    if(j == p){
      continue;
    }
    ans = max(ans, w + DownDFS(j, i));
  }
  dp[i] = ans;
  return ans;
}

void UpDFS(int i, int p, ll ans){
  dp[i] = max(dp[i], ans);

  vector<ll> v(adj[i].size());

  ll x = ans;
  for(int k = 0; k < adj[i].size(); ++k){
    int j, w;
    tie(j, w) = adj[i][k];

    if(j == p){
      continue;
    }

    v[k] = max(v[k], x + w);
    x = max(x, dp[j] + w);
  }

  x = ans;
  for(int k = adj[i].size() - 1; k != -1; --k){
    int j, w;
    tie(j, w) = adj[i][k];

    if(j == p){
      continue;
    }

    v[k] = max(v[k], x + w);
    x = max(x, dp[j] + w);
  }

  for(int k = 0; k < adj[i].size(); ++k){
    int j, w;
    tie(j, w) = adj[i][k];

    if(j == p){
      continue;
    }

    UpDFS(j, i, v[k]);
  }
}

void Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);
  for(int e = 1; e < n; ++e){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  DownDFS(1, 0);
  UpDFS(1, 0, 0ll);

  for(int i = 1; i <= n; ++i){
    printf("%lld ", dp[i]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}