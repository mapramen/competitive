#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

bool Check(ll k, ll s){
  s *= 2;
  s /= k;
  s /= (k + 1);
  return s > 0;
}

int main(){
  ll n, k, ans = 0;

  cin >> n >> k;

  for(ll g = 1; g * g <= n; g++){
    if(n % g != 0)
      continue;
    if(Check(k, n / g) == 1)
      ans = max(ans, g);
    if(Check(k, g) == 1)
      ans = max(ans, n / g);
  }

  if(ans == 0)
    printf("-1\n");
  else{
    for(ll i = 1; i < k; i++){
      printf("%lld ", ans * i);
      n -= ans * i;
    }
    printf("%lld\n", n);
  }

  return 0;
}
