#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int c[N];
ll s[N];

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<vector<int>> a(n, vector<int>(m));
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      scanf("%d", &a[x][y]);
    }
  }

  ll ans = 0;
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < m; ++y){
      int k = a[x][y];
      ans += 1ll * c[k] * x - s[k];
      ++c[k], s[k] += x;
    }
  }

  for(int k = 1; k < N; ++k){
    c[k] = 0, s[k] = 0;
  }

  for(int y = 0; y < m; ++y){
    for(int x = 0; x < n; ++x){
      int k = a[x][y];
      ans += 1ll * c[k] * y - s[k];
      ++c[k], s[k] += y;
    }
  }

  printf("%lld\n", ans);
  
  return 0;
}