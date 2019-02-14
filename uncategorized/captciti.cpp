#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 50001

vector< vector<int> > adj(N);
int p[N], c[N];
ll dp[2][N], inf = 1E14;

void DFS(int i, int parent){
  ll s0 = 0, s1 = 0;
  vector< ll > v(1);

  for(auto k : adj[i]){
    if(k == parent)
      continue;
    DFS(k, i);
    s0 += dp[0][k];
    s1 += dp[1][k];
    v.PB(dp[0][k] - dp[1][k]);
  }

  dp[0][i] = min(dp[0][i], s1 + p[i]);

  if(v.size() > 1){
    sort(v.begin() + 1, v.end());

    int n = v.size(), x = 1;
    ll s = 0;

    for( ; x < n && (x < c[i] || v[x] < 0); x++)
      s += v[x];

    if(x > c[i] - 1)
      dp[1][i] = min(dp[1][i], s1 + s);

    for( ; x < n && (x <= c[i] || v[x] < 0); x++)
      s += v[x];

    if(x > c[i])
      dp[0][i] = min(dp[0][i], s1 + s);
  }
  else{
    if(parent != 0)
      dp[1][i] = 0;
  }

  dp[1][i] = min(dp[1][i], dp[0][i]);
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
      adj[i].clear();
      for(int j = 0; j < 2; j++)
        dp[j][i] = inf;
    }

    for(int x = 1; x < n; x++){
      int i, j;
      scanf("%d%d", &i, &j);
      adj[i].PB(j);
      adj[j].PB(i);
    }

    for(int i = 1; i <= n; i++)
      scanf("%d", &p[i]);

    for(int i = 1; i <= n; i++)
      scanf("%d", &c[i]);

    DFS(1, 0);

    printf("%lld\n", dp[0][1]);
  }

  return 0;
}
