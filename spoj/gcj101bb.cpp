#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 51

int x[N], v[N];
bool is_reachable[N];

string Solve(){
  int n, k, b, t;
  scanf("%d%d%d%d", &n, &k, &b, &t);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &x[i]);
    x[i] = b - x[i];
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &v[i]);
  }

  for(int i = 1; i <= n; ++i){
    is_reachable[i] = x[i] <= 1ll * v[i] * t;
  }

  int ans = 0;
  for(int i = n; i != 0 && k != -0; --i){
    if(!is_reachable[i]){
      continue;
    }

    for(int j = i + 1; j <= n; ++j){
      ans += (!is_reachable[j] && 1ll * x[i] * v[j] < 1ll * x[j] * v[i]);
    }

    --k;
  }

  return k != 0 ? "IMPOSSIBLE" : to_string(ans);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %s\n", k, Solve().c_str());
  }
  return 0;
}