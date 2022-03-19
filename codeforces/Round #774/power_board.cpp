#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int max_root_power[N];
bool visited[N];
map<int,int> dp;

void Initialise(){
  for(int i = 1; i < N; ++i){
    max_root_power[i] = 1;
  }

  for(int i = N - 1; i != 1; --i){
    for(ll j = 1ll * i * i, k = 2; j < N; j *= i, ++k){
      max_root_power[j] = k;
    }
  }
}

int DP(int m, int k){
  if(dp.count(k) != 0){
    return dp[k];
  }

  for(int i = 1; i <= m; ++i){
    visited[i] = true;
  }

  for(int i = 1; i < k; ++i){
    ll lcm = 1ll * i * k / __gcd(i, k);
    ll x = lcm / i, y = lcm / k;
    for(ll px = 0, py = 0; px <= m; px += x, py += y){
      visited[py] = false;
    }
  }

  int c = 0;
  for(int i = 1; i <= m; ++i){
    c += visited[i];
  }

  dp[k] = c;
  return c;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  Initialise();

  ll ans = 1;
  for(int i = 2; i <= n; ++i){
    ans += DP(m, max_root_power[i]);
  }

  printf("%lld\n", ans);

  return 0;
}