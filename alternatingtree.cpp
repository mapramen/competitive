#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define MOD 1000000007

vector< vector<int> > adj(N);
ll a[N], c[N][2], dp[N][2], s[N];

ll Solve(int i, int k){
  ll ans = 0;
  for(int x = 0; x < 2; ++x){
    for(int y = 0; y < 2; ++y){
      ll a = x == 0 ? (MOD - dp[i][x]) % MOD : dp[i][x];
      ll b = x == 0 ? dp[k][y] : (MOD - dp[k][y]) % MOD;
      ll ansx = (c[i][x] * b + c[k][y] * a) % MOD;
      ans = (ans + ansx) % MOD;
    }
  }
  return ans;
}

void DFS(int i, int p){
  c[i][1] = 1;
  dp[i][1] = a[i];
  ll ans = 0;

  for(auto k : adj[i]){
    if(k == p)
      continue;
    DFS(k, i);
    ans = (ans + Solve(i, k) + Solve(k, i)) % MOD;
    for(int x = 0; x < 2; ++x){
      c[i][x] += c[k][1 - x];
      dp[i][x] = (dp[i][x] + c[k][1 - x] * a[i] + MOD - dp[k][1 - x]) % MOD;
    }
  }

  s[i] = ans;
}

int main(){
  int n;

  scanf("%d", &n);

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
    a[i] = (MOD + a[i]) % MOD;
    ans = (ans + a[i]) % MOD;
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS(1, 0);

  for(int i = 1; i <= n; ++i)
    ans = (ans + s[i]) % MOD;

  printf("%lld\n", ans);

  return 0;
}
