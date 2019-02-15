#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 3

double dp[B];

int main(){
  int n;
  double p, q, ans;

  scanf("%d", &n);

  q = ans = 0;
  while(n--){
    scanf("%lf", &p);
    ans += (1 - p) * dp[2];
    dp[2] = p * (1 - q + dp[2] + 2 * dp[1] + dp[0]);
    dp[1] = p * (1 - q + dp[1] + dp[0]);
    dp[0] = p * (1 - q + dp[0]);
    q = p;
  }

  ans += dp[2];

  printf("%.15lf\n", ans);

  return 0;
}
