#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101
#define B 12
#define M (1 << B)

int d[N][N], dp[M][B], inf = 1E8;

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      d[i][j] = inf;
    }
    d[i][i] = 0;
  }
}

int Dis(int i, int j){
  return d[i][j];
}

int Calculate(int s, vector<pii>& v){
  int n = v.size(), m = (1 << n);

  for(int mask = 0; mask < m; ++mask){
    for(int i = 0; i < n; ++i){
      dp[mask][i] = inf;
    }
  }

  for(int i = 0; i < n; ++i){
    dp[(1 << i)][i] = Dis(s, v[i].first) + Dis(v[i].first, v[i].second);
  }

  for(int mask = 1; mask < m; ++mask){
    for(int i = 0; i < n; ++i){
      if(dp[mask][i] == inf){
        continue;
      }
      for(int j = 0; j < n; ++j){
        if((mask & (1 << j)) != 0){
          continue;
        }
        int nmask = mask | (1 << j);
        dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + Dis(v[i].second, v[j].first) + Dis(v[j].first, v[j].second));
      }
    }
  }

  int ans = inf;
  for(int i = 0; i < n; ++i){
    ans = min(ans, dp[m - 1][i] + Dis(v[i].second, s));
  }

  return ans;
}

int Solve(){
  int n, m, s;
  scanf("%d%d%d", &n, &m, &s);

  Reset(n);

  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    d[i][j] = min(d[i][j], w);
    d[j][i] = min(d[j][i], w);
  }

  for(int k = 1; k <= n; ++k){
    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= n; ++j){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int q;
  scanf("%d", &q);

  vector<pii> v;
  while(q--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    while(k--){
      v.push_back({i, j});
    }
  }

  return Calculate(s, v);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}