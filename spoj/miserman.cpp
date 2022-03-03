#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> dp(m + 2), t(n + 2);
  while(n--){
    for(int i = 1; i <= m; ++i){
      int x;
      scanf("%d", &x);
      t[i] = x + min(dp[i], min(dp[i - 1], dp[i + 1]));
    }
    dp.swap(t);
    dp[0] = INT_MAX / 2, dp[m + 1] = INT_MAX / 2;
  }

  printf("%d\n", *min_element(dp.begin(), dp.end()));

  return 0;
}