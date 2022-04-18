#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 51
#define M 1000

int tolls[N][N], times[N][N];
ll dp[N][M];
priority_queue<pii,vector<pii>,greater<pii>> Q;

void CheckAndPush(int i, int t, ll val){
  if(val < dp[i][t]){
    dp[i][t] = val;
    Q.push({t, i});
  }
}

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  if(n == 0){
    exit(0);
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      scanf("%d", &times[i][j]);
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      scanf("%d", &tolls[i][j]);
    }
  }

  for(int i = 0; i <= n; ++i){
    for(int t = 0; t <= m; ++t){
      dp[i][t] = LLONG_MAX;
    }
  }

  CheckAndPush(1, 0, 0);
  while(!Q.empty()){
    int i, t;
    tie(t, i) = Q.top();
    Q.pop();

    for(int j = 1; j <= n; ++j){
      CheckAndPush(j, t + times[i][j], dp[i][t] + tolls[i][j]);
    }
  }

  ll ans_toll = LLONG_MAX;
  int ans_time = -1;

  for(int t = 0; t <= m; ++t){
    if(dp[n][t] < ans_toll){
      ans_toll = dp[n][t], ans_time = t;
    }
  }

  printf("%lld %d\n", ans_toll, ans_time);
}

int main(){
  while(true){
    Solve();
  }
  return 0;
}