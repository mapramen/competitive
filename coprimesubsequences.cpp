#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define MOD 1000000007

ll pow2[N], dp[N];

void PreProcess(){
  pow2[0] = 1;
  for(int i = 1; i < N; i++)
    pow2[i] = (2 * pow2[i - 1]) % MOD;
}

int main(){
  int n;

  PreProcess();

  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    int a;
    scanf("%d", &a);
    dp[a]++;
  }

  for(int i = 1; i < N; i++)
    for(int j = i + i; j < N; j += i)
      dp[i] += dp[j];

  for(int i = N - 1; i > 0; i--){
    dp[i] = (pow2[dp[i]] + MOD - 1) % MOD;
    ll dpx = 0;
    for(int j = i + i; j < N; j += i)
      dpx = (dpx + dp[j]) % MOD;
    dp[i] = (dp[i] + MOD - dpx) % MOD;
  }

  printf("%lld\n", dp[1]);

  return 0;
}
