#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

double dp[N];

double Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int j = 0; j <= m; ++j){
    dp[j] = 0;
  }

  dp[0] = 1;
  for(int i = 1; i <= n; ++i){
    double p;
    scanf("%lf", &p);

    for(int j = m; j != 0; --j){
      dp[j] = p * dp[j - 1] + (1 - p) * dp[j];
    }

    dp[0] *= (1 - p);
  }

  return dp[m];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%.10lf\n", Solve());
  }
  return 0;
}