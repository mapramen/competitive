#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5000
#define MOD 1000000007
#define INV2 500000004

ll dp1[2 * N], dp2[2 * N], a[N], ans[2 * N], c[N];

int main(){
  int n, m;

  scanf("%d", &n);
  m = 2 * (n - 1);

  a[0] = 1;
  for(int i = 1; i < n; ++i)
    scanf("%lld", &a[i]);

  c[0] = 1;
  for(int i = 1; i < n; ++i)
    c[i] = (a[i] * c[i - 1]) % MOD;

  for(int i = 0; i < n; ++i){
    memset(dp1, 0, sizeof(dp1));

    dp1[0] = 1;
    for(int j = 1; i + j < n; ++j)
      dp1[j] = (a[i + j] * dp1[j - 1]) % MOD;

    for(int j = n - 1 + i; j > 0; --j)
      dp2[j] = (dp2[j - 1] + (j >= 2 ? (a[i] - 1) * dp1[j - 2] : 0ll)) % MOD;
    dp2[0] = 1;

    for(int j = n - 1 + i; j > 0; --j)
      ans[j] = (ans[j] + c[i] * (dp1[j] + dp2[j])) % MOD;
  }

  for(int j = 1; j <= m; ++j){
    ans[j] = (INV2 * ans[j]) % MOD;
    printf("%lld ", ans[j]);
  }
  printf("\n");

  return 0;
}
