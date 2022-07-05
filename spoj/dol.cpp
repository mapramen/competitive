#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  ll n;
  scanf("%lld", &n);

  while(n % 2 == 0){
    n /= 2;
  }

  return n;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %lld\n", k, Solve());
  }
  return 0;
}