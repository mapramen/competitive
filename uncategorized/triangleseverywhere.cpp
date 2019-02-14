#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

#define MOD 1000000007

ll ModExp(ll a, int n){
  ll ans = 1 % MOD;
  while(n){
    if(n % 2)
      ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    n /= 2;
  }
  return ans;
}

int main(){
  int q;

  scanf("%d", &q);
  while(q--){
    int n;
    scanf("%d", &n);
    ll ans = (2 * ModExp(3ll, n) + MOD - 1) % MOD;
    printf("%lld\n", ans);
  }

  return 0;
}
