#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define MOD 1000000009

vector<pii> a;
int dp[2][N];

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= m; ++i){
    for(int j = 2 * i; j <= m; j += i){
      a.push_back({i, j});
      a.push_back({j, i});
    }
    a.push_back({i, i});
  }

  int cur = 0;
  dp[cur][1] = 1;
  for(int i = 1; i <= n; ++i, cur ^= 1){
    int nxt = 1 ^ cur;

    for(int j = 1; j <= m; ++j){
      dp[nxt][j] = 0;
    }

    for(pii& p: a){
      int j, k;
      tie(j, k) = p;
      dp[nxt][j] = (dp[nxt][j] + dp[cur][k]) % MOD;
    }
  }

  int ans = 0;
  for(int j = 1; j <= m; ++j){
    ans = (ans + dp[cur][j]) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}