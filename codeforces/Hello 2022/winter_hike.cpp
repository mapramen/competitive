#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 501

int a[N][N];

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x <= 2 * n; ++x){
    for(int y = 1; y <= 2 * n; ++y){
      scanf("%d", &a[x][y]);
    }
  }

  int m = INT_MAX;
  m = min(m, a[1][n + 1]);
  m = min(m, a[1][2 * n]);
  m = min(m, a[n][n + 1]);
  m = min(m, a[n][2 * n]);
  m = min(m, a[n + 1][1]);
  m = min(m, a[n + 1][n]);
  m = min(m, a[2 * n][1]);
  m = min(m, a[2 * n][n]);

  ll ans = m;
  for(int x = n + 1; x <= 2 * n; ++x){
    for(int y = n + 1; y <= 2 * n; ++y){
      ans += a[x][y];
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