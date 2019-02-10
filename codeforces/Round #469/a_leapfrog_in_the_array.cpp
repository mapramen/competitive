#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  ll n, q;

  scanf("%lld%lld", &n, &q);
  while(q--){
    ll m;
    scanf("%lld", &m);
    while(m % 2 == 0)
      m += (n - m / 2);
    printf("%lld\n", (m + 1) / 2);
  }

  return 0;
}
