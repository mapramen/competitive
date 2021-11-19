#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Pow10(int n){
  ll ans = 1;
  while(n--){
    ans *= 10;
  }
  return ans;
}

ll Solve(){
  ll n, k;
  scanf("%lld%lld", &n, &k);

  vector<int> a;
  while(n--){
    int x;
    scanf("%d", &x);
    a.push_back(x);
  }
  a.push_back(18);
  
  ll ans = 0;
  for(int i = 0; i < a.size() - 1; ++i){
    ll x = Pow10(a[i]), y = Pow10(a[i + 1]);
    ll z = y / x - 1;

    if(z <= k){
      ans += x * z;
      k -= z;
    }
    else{
      ans += (k + 1) * x;
      k = 0;
      break;
    }
  }
  
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%lld\n", Solve());
  }

  return 0;
}