#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001

vector<vector<int>> adj(N);
int n, MOD, dp[N][N], s[N], a[N], b[N], c[N][N];

void UpdateA(vector<int>& v){
  int val = 1;
  for(int j: v){
    a[j] = (1ll * val * a[j]) % MOD;
    val = (1ll * val * s[j]) % MOD;
  }
}

void DFS(int i, int p){
  vector<int> v;
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
    v.push_back(j);
  }

  for(int x = 1; x <= n; ++x){
    for(int j: v){
      a[j] = x != 1;
    }

    UpdateA(v);
    reverse(v.begin(), v.end());
    UpdateA(v);

    int ans = 1;
    for(int j: v){
      s[j] = (s[j] + dp[j][x]) % MOD;
      ans = (1ll * ans * s[j]) % MOD;
    }

    if(i != 1){
      for(int j: v){
        b[j] = (b[j] + a[j]) % MOD;
        ans = (ans + 1ll * dp[j][x] * b[j]) % MOD;
      }
    }

    dp[i][x] = ans;
  }
}

int main(){
  scanf("%d%d", &n, &MOD);

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    s[i] = 0, b[i] = 0;
  }

  DFS(1, 0);

  for(int i = 0; i <= n; ++i){
    c[i][0] = 1;
    for(int j = 1; j <= i; ++j){
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }

  a[0] = 0;
  for(int x = 1; x < n; ++x){
    int ans = dp[1][x];
    for(int y = 0; y < x; ++y){
      ans = (ans + MOD - ((1ll * c[x][y] * a[y]) % MOD)) % MOD;
    }
    a[x] = ans;
    printf("%d ", ans);
  }
  printf("\n");

  return 0;
}