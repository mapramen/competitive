#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 19
#define N (1 << B)
#define M 71
#define MOD 1000000007

ll dp[2][N];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67}, a[M], c[N];

void Initialise(){
  for(int n = 1; n < M; ++n){
    int mask = 0;
    for(int i = 0; i < B; ++i){
      int j = primes[i], x = n;
      while(x % j == 0){
        mask ^= (1 << i);
        x /= j;
      }
    }
    a[n] = mask;
  }
}

ll Pow2(int n){
  ll ans = 1 % MOD;
  for( ; n > 0; --n)
    ans = (ans + ans) % MOD;
  return ans;
}

int main(){
  ll ans = 0;
  Initialise();

  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ++c[a[x]];
  }

  dp[0][0] = 1;

  for(int x = 0, cur = 0; x < N; ++x){
    if(c[x] == 0)
      continue;

    int nxt = 1 - cur;
    for(int j = 0; j < N; ++j)
      dp[nxt][j] = 0;

    ll val = Pow2(c[x] - 1);
    for(int i = 0; i < N; ++i)
      dp[nxt][i] = (val * (dp[cur][i] + dp[cur][(x ^ i)])) % MOD;

    cur = 1 - cur;
    ans = (dp[cur][0] + MOD - 1) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}
