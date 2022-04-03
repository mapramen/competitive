#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 100001
#define M 201

vector<vector<tiii>> V(N);
int a[N], inf = 1000000001;
int dp[N][M];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    V[i].clear();
  }
}

int GetMinTime(vector<tiii>& v, vector<int>& ans){
  for(int i = 1; i < M; ++i){
    dp[0][i] = inf;
  }

  for(int x = 1; x <= v.size(); ++x){
    auto [k, t, p] = v[x - 1];
    
    for(int i = M - 1; i != -1; --i){
      dp[x][i] = dp[x - 1][i];
    }

    for(int i = M - 1, j = i - p; j >= 0; --i, --j){
      dp[x][i] = min(dp[x][i], t + dp[x - 1][j]);
    }
  }

  int t = inf, i = -1, x = v.size();
  for(int j = 100; j < M; ++j){
    if(dp[x][j] < t){
      t = dp[x][j], i = j;
    }
  }

  if(t == inf){
    return t;
  }

  for( ; x != 0; --x){
    if(dp[x][i] == dp[x - 1][i]){
      continue;
    }
    auto [k, _, p] = v[x - 1];
    ans.push_back(k), i -= p;
  }

  return t;
}

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  Reset(n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int k = 1; k <= m; ++k){
    int e, t, p;
    scanf("%d%d%d", &e, &t, &p);
    V[e].push_back({k, t, p});
  }

  int T = 0;
  vector<int> ans;
  for(int i = 1; i <= n; ++i){
    int ti = GetMinTime(V[i], ans);
    T += ti;

    // printf("i = %d ai = %d ti = %d T = %d\n", i, a[i], ti, T);

    if(T > a[i]){
      printf("-1\n");
      return;
    }
  }

  printf("%lu\n", ans.size());
  for(int k: ans){
    printf("%d ", k);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}