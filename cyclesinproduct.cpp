#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 4001
#define K 76
#define MOD 998244353

vector< vector<int> > adj(N);
vector< vector<ll> > dp[K];
int M[N][N];
ll C[K][K], A[K], B[K];

void Initialise(){
  for(int i = 0; i < K; ++i){
    C[i][0] = 1;
    for(int j = 1; j <= i; ++j){
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    dp[i].resize(N);
  }
}

void Solve(int n, int m, ll ans[]){
  for(int i = 0; i <= n; ++i){
    adj[i].PB(0);
    adj[0].PB(i);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  for(int i = 0; i <= n; ++i){
    for(int k = 0; k <= m; k += 2){
      dp[k][i].resize(adj[i].size());
    }

    int x = -1;
    for(auto j : adj[i]){
      M[i][j] = ++x;
    }

    if(i){
      fill(dp[0][i].begin(), dp[0][i].end(), 1ll);
    }
  }

  for(int k = 2; k <= m; k += 2){
    for(int i = 1; i <= n; ++i){
      for(int t = 0; t <= k - 2; t += 2){
        ll s = 0;

        for(auto j : adj[i]){
          int x = M[j][i];
          s = (s + dp[t][j][x]) % MOD;
        }

        for(auto j : adj[i]){
          int x = M[j][i], y = M[i][j];
          dp[k][i][y] = (dp[k][i][y] + (s + MOD - dp[t][j][x]) * dp[k - t - 2][i][y]) % MOD;
        }
      }

      ans[k] = (ans[k] + dp[k][i][0]) % MOD;
    }
  }

  ans[0] = n;

  for(int i = 1; i <= n; ++i){
    for(int k = 0; k <= m; k += 2){
      dp[k][i].clear();
    }
    adj[i].clear();
  }
}

int main(){
  int n1, n2, m;

  scanf("%d%d%d", &n1, &n2, &m);

  Initialise();
  Solve(n1, m, A);
  Solve(n2, m, B);

  ll ans = 0;
  for(int k = 0; k <= m; k += 2){
    ll ansx = (A[k] * B[m - k]) % MOD;
    ans = (ans + C[m][k] * ansx) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}
