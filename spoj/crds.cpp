#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000007

ll Solve(){
  int n;
  scanf("%d", &n);
  return (1ll * n * (3 * n + 1) / 2) % MOD;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}