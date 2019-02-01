#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 1000000007

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n, k;
    scanf("%d%d", &n, &k);

    if(n < (k * (k + 1)) / 2){
      printf("-1\n");
      continue;
    }

    int a = (2 * n - k * k + k) / (2 * k);
    int z = n - (k * (2 * a + k - 1)) / 2;

    ll ans = 1;

    for(int y = a + k - 1, x = a; y >= x; --y, z = max(0, z - 1)){
      int m = y + (z > 0);
      ll ansx = (1ll * m * (m - 1)) % MOD;
      ans = (ans * ansx) % MOD;
    }

    printf("%lld\n", ans);
  }

  return 0;
}
