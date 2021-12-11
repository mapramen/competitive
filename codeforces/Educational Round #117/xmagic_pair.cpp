#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  ll a, b, x;
  scanf("%lld%lld%lld\n", &a, &b, &x);

  while(min(a, b) != 0 && x <= max(a, b)){
    if(a > b){
      swap(a, b);
    }

    if((b - x) % a == 0){
      return true;
    }

    b %= a;
  }

  return x == max(a, b);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}