#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101
#define K 501

int M[N][N], W[K], a[N];

ll MaximumSubArraySum(int n){
  ll ans = LLONG_MIN, s = 0;
  for(int i = 1; i <= n; ++i){
    s = a[i] + max(0ll, s);
    ans = max(ans, s);
  }
  return ans;
}

ll Solve(){
  int n, m, h, k, t;
  scanf("%d%d%d%d%d", &n, &m, &h, &k, &t);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &M[i][j]);
    }
  }

  for(int x = 1; x <= k; ++x){
    W[x] = 0;
  }

  while(t--){
    int x;
    scanf("%d", &x);

    for(int i = 1; i <= k; ++i){
      int y;
      scanf("%d", &y);
      W[i] += x * y;
    }
  }

  ll ans = LLONG_MIN;
  for(int i = 1; i <= n; ++i){
    for(int x = 1; x <= m; ++x){
      a[x] = 0;
    }

    for(int j = i; j <= n; ++j){
      for(int x = 1; x <= m; ++x){
        a[x] += W[M[j][x]];
      }
      ans = max(ans, MaximumSubArraySum(m));
    }
  }

  return h + ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d:\n%lld\n", k, Solve());
  }
  return 0;
}