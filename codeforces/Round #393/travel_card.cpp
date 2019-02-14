#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define T1 90
#define T2 1440

int t[N], dp[N];

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &t[i]);

  t[0] = INT_MIN / 2;
  for(int i = 1, j = 0, k = 0; i <= n; i++){
    for( ; j < i && t[i] - t[j] + 1 > T1; j++);
    for( ; k < i && t[i] - t[k] + 1 > T2; k++);
    j--, k--;
    dp[i] = min(20 + dp[i - 1], min(50 + dp[j], 120 + dp[k]));
  }

  for(int i = 1; i <= n; i++){
    dp[i] = max(dp[i], dp[i - 1]);
    printf("%d\n", dp[i] - dp[i - 1]);
  }

  return 0;
}
