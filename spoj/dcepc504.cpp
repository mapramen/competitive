#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  ll n, k;
  scanf("%lld%lld", &n, &k);

  bool is_male = true;
  for(n = min(51ll, n); n != 1; --n){
    if((1ll << (n - 2)) < k){
      k -= (1ll << (n - 2));
      is_male = !is_male;
    }
  }

  return is_male;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "Male" : "Female");
  }
  return 0;
}