#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001
#define MOD 1000000007

int a[N], dp[N];

int Solve(){
  int n, l;
  scanf("%d%d", &n, &l);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  dp[0] = 1, a[0] = INT_MIN;
  sort(a + 1, a + n + 1);

  int ans = 1;
  for(int i = 1; i <= n; ++i){
    int j = lower_bound(a + 1, a + n + 1, a[i] - l + 1) - a - 1;
    ans = (ans + dp[j]) % MOD;
    dp[i] = ans;
  }

  return (MOD + ans - 1) % MOD;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}