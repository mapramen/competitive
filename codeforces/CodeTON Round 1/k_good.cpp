#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool IsKGood(ll n, ll k){
  return k != 1 && 2 * n / k >= k + 1;
}

ll Solve(){
  ll n;
  scanf("%lld", &n);

  ll a = 1, b = 2 * n;
  while(b % 2 == 0){
    a *= 2, b /= 2;
  }

  if(IsKGood(n, a)){
    return a;
  }

  if(IsKGood(n, b)){
    return b;
  }

  return -1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}