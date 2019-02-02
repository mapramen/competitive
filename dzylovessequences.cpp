#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int a[N], dp[N];

int main(){
  int n, ans = 0;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; i++){
    if(a[i - 1] < a[i])
      dp[i] = 1 + dp[i - 1];
    else
      dp[i] = 1;

    int j = i - dp[i];

    if(j > 0 && a[j - 1] + 1 < a[j + 1])
      ans = max(ans, dp[j - 1] + 1 + dp[i]);

    if(dp[i] > 1 && a[j] + 1 < a[j + 2])
      ans = max(ans, dp[j] + dp[i]);

    ans = max(ans, min(i, 1 + dp[i]));
    ans = max(ans, 1 + dp[i - 1]);
  }

  printf("%d\n", ans);

  return 0;
}
