#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  ll n;
  scanf("%lld", &n);

  ll s = 0;
  for(int i = 1; i <= n; ++i){
    ll x;
    scanf("%lld", &x);
    x %= n;
    s = (s + x) % n;
  }

  return s == 0;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}