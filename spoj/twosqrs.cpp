#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool IsSquare(ll n){
  ll x = sqrt(max(0ll, n - 2));
  while(x * x < n){
    ++x;
  }
  return x * x == n;
}

bool Solve(){
  ll n;
  scanf("%lld", &n);

  for(ll x = 0; 2 * x * x <= n; ++x){
    if(IsSquare(n - x * x)){
      return true;
    }
  }

  return false;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "Yes" : "No");
  }
  return 0;
}