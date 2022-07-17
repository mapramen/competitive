#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5002

int a[N], dp_prefix[N][N], dp_suffix[N][N];

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 0; i <= n + 1; ++i){
    for(int x = 1; x <= n; ++x){
      dp_prefix[i][x] = 0, dp_suffix[i][x] = 0;
    }
  }

  for(int i = 2; i <= n; ++i){
    for(int x = 1; x <= n; ++x){
      dp_prefix[i][x] = dp_prefix[i - 1][x];
    }

    for(int x = a[i - 1]; x <= n; ++x){
      ++dp_prefix[i][x];
    }
  }

  for(int i = n - 1; i != 1; --i){
    for(int x = 1; x <= n; ++x){
      dp_suffix[i][x] = dp_suffix[i + 1][x];
    }

    for(int x = a[i + 1]; x <= n; ++x){
      ++dp_suffix[i][x];
    }
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      ans += dp_prefix[i][a[j]] * dp_suffix[j][a[i]];
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}