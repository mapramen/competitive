#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  ll n, m;
  scanf("%lld%lld", &n, &m);
  return m * (m + 1) / 2 + n * (n - 1) * m / 2 + (n - 1) * m;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}