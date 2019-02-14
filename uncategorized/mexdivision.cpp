#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500001
#define MOD 1000000007

int a[N], c[N], dp[N], n, k, t = 0;

void Add(int x){
  if(x > k)
    return ;

  c[x]++;
  t += (c[x] == 1);
}

void Subtract(int x){
  if(x > k)
    return ;

  c[x]--;
  t -= (c[x] == 0);
}

int main(){
  ll ans = 0;

  scanf("%d%d", &n, &k);

  if(k >= n){
    ans = 1;
    for(int x = 1; x < n; x++)
      ans = (2 * ans) % MOD;
  }
  else{
    for(int i = 1; i <= n; i++)
      scanf("%d", &a[i]);

    dp[0] = 1;

    for(int i = 1, j = 1, ansx = 1; i <= n; i++){
      Add(a[i]);

      for( ; j <= i && t >= k + 1; j++){
        Subtract(a[j]);
        ansx = (ansx + MOD - dp[j - 1]) % MOD;
      }

      dp[i] = ansx;
      ansx = (ansx + dp[i]) % MOD;
    }
    ans = dp[n];
  }

  printf("%lld\n", ans);

  return 0;
}
