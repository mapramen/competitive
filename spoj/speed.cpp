#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  ll s1, s2;
  scanf("%lld%lld", &s1, &s2);
  ll b = abs(s2 - s1), a = abs(s1);
  ll g = __gcd(b, a);
  return b / g;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}