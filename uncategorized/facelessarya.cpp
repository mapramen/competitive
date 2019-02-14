#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 501
#define M 1000001

int leastPrime[M], c[M], v[M], a[N], dp[N];

void Initialise(){
  for(int i = 2; i < M; ++i)
    for(int j = i; j < M; j += i)
      if(leastPrime[j] == 0)
        leastPrime[j] = i;
}

int main(){
  Initialise();
  int t;

  scanf("%d", &t);
  while(t--){
    int n, m;
    scanf("%d%d", &n, &m);

    for(int k = 1; k < M; ++k)
      c[k] = v[k] = 0;

    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= m; ++j)
        scanf("%d", &a[j]);

      for(int j = 1; j <= m; ++j){
        dp[j] = 0;
        for(int x = a[j]; x > 1; x /= leastPrime[x]){
          int k = leastPrime[x];
          if(v[k] == i - 1)
            dp[j] = max(dp[j], a[j] + c[k]);
        }
      }

      for(int j = 1; j <= m; ++j){
        if(dp[j] == 0)
          continue;
        for(int x = a[j]; x > 1; x /= leastPrime[x]){
          int k = leastPrime[x];
          if(v[k] == i)
            c[k] = max(c[k], dp[j]);
          else
            c[k] = dp[j], v[k] = i;
        }
      }
    }

    int ans = 0;
    for(int j = 1; j <= m; ++j)
      ans = max(ans, dp[j]);

    printf("%d\n", ans);
  }

  return 0;
}
