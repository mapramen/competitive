#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define B 4
#define N 500001

vector<vector<pii>> V(N);
priority_queue<pli> Q;
int a[B][N];
ll dp[B][N], inf = 1E18;

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i < B; ++i){
    for(int j = 1; j <= n; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  while(q--){
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    V[l].push_back({r, k});
  }

  for(int i = 0; i < B; ++i){
    for(int j = 0; j <= n; ++j){
      dp[i][j] = -inf;
    }
  }

  dp[1][0] = 0;
  for(int j = 1; j <= n; ++j){
    dp[1][j] = dp[1][j - 1] + a[1][j];
  }

  ll s = 0;
  for(int j = 1; j <= n; ++j){
    while(!)
  }

  for(int j = 1; j <= n; ++j){
    dp[3][j] = max(dp[3][j - 1], dp[2][j]) + a[3][j];
  }

  printf("%lld\n", dp[3][n]);
  return 0;
}