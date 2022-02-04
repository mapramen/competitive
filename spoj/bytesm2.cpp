#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> dp(m + 2), t(m + 2);

  while(n--){
    for(int j = 1; j <= m; ++j){
      int x;
      scanf("%d", &x);
      t[j] = x + max(dp[j - 1], max(dp[j], dp[j + 1]));
    }
    swap(dp, t);
  }

  return *max_element(dp.begin(), dp.end());
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}