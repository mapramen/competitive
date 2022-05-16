#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  ll n, k, m;
  scanf("%lld%lld%lld", &n, &k, &m);

  int ans = 0;
  while(n <= m / k){
    ++ans;
    n *= k;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}