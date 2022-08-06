#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 25
#define M 31

ll dp[N][M], inf = 1E18;

ll Solve(){
  int n, hiring_cost, monthly_salary, severance_pay;
  scanf("%d", &n);
  if(n == 0){
    exit(0);
  }

  scanf("%d%d%d", &hiring_cost, &monthly_salary, &severance_pay);

  for(int i = 0; i <= n; ++i){
    for(int j = 0; j < M; ++j){
      dp[i][j] = inf;
    }
  }

  dp[0][0] = 0;

  for(int i = 1; i <= n; ++i){
    int m;
    scanf("%d", &m);

    for(int j = 0; j < M; ++j){
      dp[i][j] = dp[i - 1][j];
    }

    for(int j = M - 2; j != -1; --j){
      dp[i][j] = min(dp[i][j], dp[i][j + 1] + severance_pay);
    }

    for(int j = 1; j < M; ++j){
      dp[i][j] = min(dp[i][j], dp[i][j - 1] + hiring_cost);
    }

    for(int j = 0; j < M; ++j){
      dp[i][j] += 1ll * j * monthly_salary;
    }

    for(int j = 0; j < m; ++j){
      dp[i][j] = inf;
    }
  }

  return *min_element(dp[n], dp[n] + M);
}

int main(){
  for(int k = 1; ; ++k){
    printf("Case %d, cost = $%lld\n", k, Solve());
  }
  return 0;
}