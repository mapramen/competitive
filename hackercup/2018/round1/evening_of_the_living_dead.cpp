#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 9001
#define MOD 1000000007

ll dp[2][2][N];
int H[N], A[N], B[N];

ll ModExp(ll a, ll n){
  ll y = 1;
  while(n){
    if(n % 2){
      y = (y * a) % MOD;
    }
    a = (a * a) % MOD;
    n /= 2;
  }
  return y;
}

ll ModInv(ll a){
  return ModExp(a, MOD - 2);
}

int GetCompressedValue(vector<int>& v, int x){
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int Solve(){
  int n, m;
  vector<int> v(1);

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    A[i] = 0;
    B[i] = 0;
    H[i] = 0;
  }

  for(int i = 1; i < n; ++i){
    scanf("%d%d", &A[i], &B[i]);
    v.PB(A[i]);
    v.PB(B[i]);
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    H[i] = max(H[i], j);
  }

  for(int i = 1; i <= n; ++i){
    v.PB(H[i]);
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  m = v.size();

  int cur = 0;
  for(int j = 0; j < m; ++j){
    dp[0][cur][j] = 0;
    dp[1][cur][j] = 0;
  }

  dp[1][cur][0] = 1;
  for(int i = 1; i <= n; ++i, cur = 1 - cur){
    int a = A[i], b = B[i], nxt = 1 - cur;
    for(int j = 0; j < m; ++j){
      dp[0][nxt][j] = 0;
      dp[1][nxt][j] = 0;
    }

    if(H[i]){
      int k = GetCompressedValue(v, H[i]);

      for(int j = 0; j <= k; ++j){
        dp[1][cur][k] = (dp[1][cur][k] + dp[0][cur][j]) % MOD;
        dp[0][cur][j] = 0;
      }

      for(int j = 0; j < k; ++j){
        dp[1][cur][k] = (dp[1][cur][k] + dp[1][cur][j]) % MOD;
        dp[1][cur][j] = 0;
      }
    }

    for(int j = 1; j < m; ++j){
      dp[1][nxt][0] = (dp[1][nxt][0] + max(0, min(b - a + 1, b - v[j])) * dp[1][cur][j]) % MOD;
      dp[1][nxt][j] = (dp[1][nxt][j] + max(0, min(b - a + 1, v[j] - a + 1)) * dp[1][cur][j]) % MOD;
    }

    for(ll j = 0, s = 0; j < m; s = (s + dp[0][cur][j]) % MOD, ++j){
      if(v[j] < a){
        continue;
      }

      if(v[j] <= b){
        dp[0][nxt][j] = (dp[0][nxt][j] + min(v[j] - v[j - 1], v[j] - a + 1) * s + (v[j] - a + 1) * dp[0][cur][j]) % MOD;
      }
      else{
        dp[0][nxt][j] = (dp[0][nxt][j] + (b - a + 1) * dp[0][cur][j]) % MOD;
      }
    }

    for(int j = 0; j < m && i < n; ++j){
      if(v[j] < a || b < v[j]){
        continue;
      }

      dp[0][nxt][j] = (dp[0][nxt][j] + min(v[j] - a + 1, v[j] - v[j - 1]) * dp[1][cur][0]) % MOD;
    }
  }

  ll p = 0;
  for(int j = 0; j < m; ++j){
    p = (p + dp[1][cur][j]) % MOD;
  }

  ll q = 1;
  for(int i = 1; i <= n; ++i){
    q = (q * (B[i] - A[i] + 1)) % MOD;
  }

  p = (q + MOD - p) % MOD;

  q = ModInv(q);

  ll ans = (p * q) % MOD;

  return ans;
}

int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }

  return 0;
}
