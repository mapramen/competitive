#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define MOD 1000000007
#define INV2 500000004

int a[N];

int main(){
  int n;
  ll P = 1, ans = 1;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    P = (P * (1 + a[i])) % MOD;
  }

  for(int i = 1; i <= n; ++i){
    ll ansx = (P * a[i]) % MOD;
    ansx = (INV2 * ansx) % MOD;
    ans = (ans * (1 + ansx)) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}
