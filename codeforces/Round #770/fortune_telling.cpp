#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  ll n, x, y;
  scanf("%lld%lld%lld", &n, &x, &y);

  ll s = x ^ y;
  while(n--){
    ll a;
    scanf("%lld", &a);
    s ^= a;
  }

  return s % 2 == 0;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "Alice" : "Bob");
  }
  return 0;
}