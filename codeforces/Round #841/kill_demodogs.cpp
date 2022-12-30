#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

int Solve(){
  int n;
  scanf("%d", &n);

  int ans = (1ll * n * (n + 1)) % MOD;
  ans = (1ll * ans * (4ll * n - 1)) % MOD;
  ans = (1ll * 166666668 * ans) % MOD;

  return (1ll * 2022 * ans) % MOD;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}