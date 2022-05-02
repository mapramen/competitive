#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  ll s = 0, r = 0;
  while(n--){
    int x;
    scanf("%d", &x);

    s += x, r += x * x;
  }

  if(s == r){
    return to_string(0);
  }

  if(k == 1){
    ll x = r - s * s;
    
    if(s == 0 || x % (2 * s) != 0){
      return "IMPOSSIBLE";
    }

    return to_string(x / (2 * s));
  }

  ll y = 1 - s, x = (r + s * s - 2 * s) / 2;
  return to_string(y) + " " + to_string(x);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %s\n", k, Solve().c_str());
  }
  return 0;
}