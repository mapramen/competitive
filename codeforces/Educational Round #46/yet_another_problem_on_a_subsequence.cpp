#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define MOD 998244353

int dp[N];

int main(){
  int n;

  scanf("%d", &n);

  dp[0] = 1;
  while(n--){
    int i, x = dp[0];
    scanf("%d", &i);

    for(int x = 1; x < N; ++x){
      dp[x - 1] = (dp[x - 1] + dp[x]) % MOD;
    }

    if(i > 0 && i < N){
      dp[i] = (dp[i] + x) % MOD;
    }
  }

  printf("%d\n", (dp[0] + MOD - 1) % MOD);

  return 0;
}
