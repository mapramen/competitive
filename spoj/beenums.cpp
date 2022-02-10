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

  if(n == -1){
    exit(0);
  }

  n = 4 * n - 1;
  
  if(n % 3 != 0){
    return false;
  }

  n /= 3;

  return n % 2 == 1 && IsSquare(n);
}

int main(){
  while(true){
    printf("%s\n", Solve() ? "Y" : "N");
  }
  return 0;
}