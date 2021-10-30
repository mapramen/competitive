#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  ll n;
  scanf("%lld", &n);

  int k = max(0.0, (sqrt(1 + 8 * n) - 1) / 2 - 5);
  while(k * (k + 1) < 2 * n){
    ++k;
  }

  return 2 * k;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%d\n", Solve());
  }

  return 0;
}