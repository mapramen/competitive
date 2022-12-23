#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

char s[N];
int ontrack_dp[N], offtrack_dp[N];

int Solve(){
  int n, m;
  scanf("%d%d%s", &n, &m, s);

  for(int j = 0; j <= m; ++j){
    ontrack_dp[j] = 0, offtrack_dp[j] = 2;
  }

  for(int i = 2; i <= n; ++i){
    for(int j = 0; j <= m; ++j){
      ++ontrack_dp[j];
    }

    if(s[i - 1] == '#'){
      for(int j = 0; j < m; ++j){
        ontrack_dp[j] = ontrack_dp[j + 1];
      }
      ontrack_dp[m] = 4 * n;
    }

    for(int j = 0; j <= m; ++j){
      offtrack_dp[j] = 2 + min(offtrack_dp[j], ontrack_dp[j]);
    }

    if(s[i - 1] != '#'){
      for(int j = 0; j <= m; ++j){
        ontrack_dp[j] = min(ontrack_dp[j], 2 + offtrack_dp[j]);
      }
    }
  }

  return *min_element(ontrack_dp, ontrack_dp + m + 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}