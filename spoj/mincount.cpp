#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  ll n;
  scanf("%lld", &n);

  n = max(0ll, n - 1);
  ll k = n / 3;

  return 3 * (k * (k + 1) / 2) + (k + 1) * (n % 3);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}