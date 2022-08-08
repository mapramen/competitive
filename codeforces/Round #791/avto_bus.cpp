#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  ll n;
  scanf("%lld", &n);

  if(n % 2 == 1 || n < 4){
    printf("-1\n");
    return;
  }

  n /= 2;
  ll x = n / 3 + (n % 3 != 0), y = n / 2;
  printf("%lld %lld\n", x, y);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}