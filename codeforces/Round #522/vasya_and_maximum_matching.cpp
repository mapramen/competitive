#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define MOD 998244353

vector< vector<int> > adj(N);
ll dp[N][3];

void DFS(int i, int p = 0){
  ll val0 = 1, val1 = 0, val2 = 1, s = 1;
  
  for(auto j : adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
    ll a = dp[j][0] + dp[j][1], b = a + dp[j][1];
    val0 = (val0 * a) % MOD;
    val1 = (val1 * b + s * dp[j][2]) % MOD;
    val2 = (val2 * b) % MOD;
    s = (s * b) % MOD;
  }

  dp[i][0] = val0;
  dp[i][1] = val1;
  dp[i][2] = val2;
}

int main(){
  int n;

  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS(1);

  ll ans = (dp[1][0] + dp[1][1]) % MOD;

  printf("%lld\n", ans);

  return 0;
}
