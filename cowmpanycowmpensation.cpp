#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 3001
#define MOD 1000000007

vector< vector<int> > adj(N);
int m;
ll c[N][N], dp[N][N], f[N];

void Initialise(int n, int D){
  m = min(n, D);
  vector<int> v;

  for(int i = 1; i <= m; ++i){
    v.PB(D - i + 1);
    int x = i;

    for(int j = 0; j < v.size() && x > 1; ++j){
      int g = __gcd(v[j], x);
      x /= g;
      v[j] /= g;
    }

    sort(v.begin(), v.end(), greater<int>());

    while(v.back() == 1){
      v.pop_back();
    }

    ll ansx = 1;
    for(auto x : v){
      ansx = (ansx * x) % MOD;
    }

    f[i] = ansx;
  }

  for(int i = 0; i <= m; ++i){
    c[i][0] = 1;
    for(int j = 1; j <= i; ++j){
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }
}

void DFS(int i){
  for(int x = 1; x <= m; ++x){
    dp[i][x] = 1;
  }

  for(auto k : adj[i]){
    DFS(k);
    ll s = 0;
    for(int x = 1; x <= m; ++x){
      s = (s + dp[k][x]) % MOD;
      dp[i][x] = (s * dp[i][x]) % MOD;
    }
  }
}

int main(){
  int n, D;

  scanf("%d%d", &n, &D);

  for(int i = 2; i <= n; ++i){
    int p;
    scanf("%d", &p);
    adj[p].PB(i);
  }

  Initialise(n, D);
  DFS(1);

  ll ans = 0;
  for(int x = 1; x <= m; ++x){
    ll s = 0;
    for(int y = 1; y < x; ++y){
      s = (s + c[x - 1][y - 1] * dp[1][y]) % MOD;
    }
    dp[1][x] = (dp[1][x] + MOD - s) % MOD;
    ans = (ans + f[x] * dp[1][x]) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}
