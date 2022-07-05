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
  return IsSquare(n);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %s\n", k, Solve() ? "Yes" : "No");
  }
  return 0;
}